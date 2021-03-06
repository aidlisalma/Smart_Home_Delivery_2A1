#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statistique.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
         ui->setupUi(this);
         this->setWindowTitle("Delivaro");
         this->setStyleSheet(" background-color:#FFEEE7; ");
        ui->stackedWidget->setCurrentIndex(0);

        ui->tableViewRec->setModel(rtmp.afficher()); //affichage table reclamation
        ui->tableViewPub->setModel(ptmp.afficher()); //affichage table publicite
        ui->tableView_colis->setModel(tmpcolis.afficher()); //affichage table colis
        ui->tableView_part->setModel(tmp_partenaires.afficher()); //affichage table partenaires
        ui->tableViewRec->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableViewRec->setSelectionMode(QAbstractItemView::SingleSelection);


        ui->tableViewPub->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableViewPub->setSelectionMode(QAbstractItemView::SingleSelection);
        son = new QSound("sound.wav");
        click = new QSound("click.wav");


        int ret=A.connect_arduino();


            switch (ret)
            {
            case 0:
                qDebug() << "arduino is available and connected to:" << A.getarduino_port_name();
                break;
            case 1:
                qDebug() << "arduino is available but not connected to:" << A.getarduino_port_name();
                break;
            case -1:
                qDebug() << "arduino is not available";
                break;
            }

            QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::update_label()
{

    double temperature;
    donnee=A.read_from_arduino();

      qDebug() << donnee.toHex().toInt()/10+donnee.toHex().toInt()%10;



      ui->lcdNumber_temp->display(donnee.toHex().toInt()/10+donnee.toHex().toInt()%10);
      temperature= ui->lcdNumber_temp->value();
      if(temperature>=21)
      {

          ui->alerte->setEnabled(true);
      }

}



void MainWindow::on_pushButton_ajouterP_clicked()
{
click->play();
    bool nom_verif = nom_regex.exactMatch(ui->lineEdit_nom->text());
    bool id_verif=identifiant_regex.exactMatch(ui->lineEdit_ID->text());
    bool nbC_verif=nombre_commandes_regex.exactMatch(ui->lineEdit_nbC->text());
    //bool produit_verif=type_produit_regex.exactMatch(ui->lineEdit_produit->text());
    if(ui->lineEdit_ID->text()!= "" && ui->lineEdit_nbC->text()!="" && ui->lineEdit_nom->text() != "")
    {
        //if (nom_verif && id_verif && nbC_verif ) {
            QString nom=ui->lineEdit_nom->text();
            QString identifiant=ui->lineEdit_ID->text();
            int nombre_commandes=ui->lineEdit_nbC->text().toInt();
            QString type_produit=ui->comboBox_produit->currentText();

            partenaire partenaire(nom,identifiant,nombre_commandes,type_produit);

            bool test=partenaire.ajouter();
            if(test)
            {
                ui->tableView_part->setModel(tmp_partenaires.afficher());

            }
            else
            {

                if (!nom_verif)
                {
                    //QMessageBox::warning(this,"Erreur lors de l'ajout","E-mail invalid");
                    ui->lineEdit_nom->setStyleSheet("color: blue");
                }
                if (!id_verif)
                {
                    //QMessageBox::warning(this,"Erreur lors de l'ajout","CIN invalid");
                    ui->lineEdit_ID->setStyleSheet("color: blue");
                }
                if (!nbC_verif )
                {
                    //QMessageBox::warning(this,"Erreur lors de l'ajout","Téléphone invalid");
                    ui->lineEdit_nbC->setStyleSheet("color: blue");
                }


            }
        //}
    }



    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du partenaire","Veuillez remplir tous les champs à nouveau");
    }


}

void MainWindow::on_pushButton_ajouterColis_clicked()
{
click->play();
    int num_colis=ui->lineEdit_numcolis->text().toInt();
    QString adresse=ui->lineEdit_adresseliv->text();
    QString nom_exp=ui->lineEdit_expediteur->text();
    QString nom_dest=ui->lineEdit_destinataire->text();
    QDate date_livraison=ui->dateEdit_livraison->date();
    Colis colis(num_colis,adresse,nom_exp,nom_dest,date_livraison);

    bool test=colis.ajouter();
    if(test)
    {
        ui->tableView_colis->setModel(tmpcolis.afficher());

    }
    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du colis","Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_pushButton_modifier_Partenaires_clicked()
{
click->play();
    if (ui->pushButton_modifier_Partenaires->isChecked())
    {

        ui->pushButton_modifier_Partenaires->setText("Modification en cours");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PARTENAIRES");
        tableModel->select();
        ui->tableView_part->setModel(tableModel);
    }
    else
    {
        ui->pushButton_modifier_Partenaires->setText("Modifier");
        ui->tableView_part->setModel(tmp_partenaires.afficher());

    }
}

void MainWindow::on_pushButton_modifier_colis_clicked()
{
click->play();
    if (ui->pushButton_modifier_colis->isChecked())
    {
        ui->pushButton_modifier_colis->setText("Modification en cours");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("COLIS");
        tableModel->select();
        ui->tableView_colis->setModel(tableModel);
    }
    else
    {
        ui->pushButton_modifier_colis->setText("Modifier");
        ui->tableView_colis->setModel(tmpcolis.afficher());

    }
}

void MainWindow::on_pushButton_supprimer_colis_clicked()
{
click->play();
    QItemSelectionModel *select = ui->tableView_colis->selectionModel();

    int num_colis =select->selectedRows(0).value(0).data().toInt();

    if(tmpcolis.supprimer(num_colis))
    {
        ui->tableView_colis->setModel(tmpcolis.afficher());
        ui->statusbar->showMessage("colis supprimé");
    }
}

void MainWindow::on_pushButton_recherche_colis_clicked()
{
click->play();
    int NUM_COLIS = ui->lineEdit_recherche_colis->text().toInt();
    QSqlQueryModel * test=tmpcolis.chercher_colis(NUM_COLIS);
    if (ui->pushButton_recherche_colis->isChecked()){
        ui->pushButton_recherche_colis->setText("En cours");

        if(test != nullptr)
        {
            QMessageBox::information(nullptr, QObject::tr("chercher un colis"),
                                     QObject::tr("colis trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_colis->setModel(test);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher un colis"),
                                  QObject::tr("Erreur , colis introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_colis->setModel(test);
        }}
    else
    {
        ui->pushButton_recherche_colis->setText("Recherche");
        ui->tableView_colis->setModel(tmpcolis.afficher());

    }
}

void MainWindow::on_pushButton_export_colis_clicked()
{
click->play();
        tmpcolis.exporter(ui->tableView_colis);
            ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

void MainWindow::on_pushButton_tabcolis_clicked()
{click->play();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->statusbar->showMessage("0");
}

void MainWindow::on_pushButton_tabpartenaires_clicked()
{   click->play();
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->statusbar->showMessage("1");
}


void MainWindow::on_pushButton_triColis_clicked()
{
click->play();
    if(ui->radioButton_numcolis->isChecked())
    {
        ui->tableView_colis->setModel(tmpcolis.trier("NUM_COLIS",ui->AD->currentText()));
    }
    else if(ui->radioButton_adresse->isChecked())
    {
        ui->tableView_colis->setModel(tmpcolis.trier("ADRESSE",ui->AD->currentText()));
    }
    else if(ui->radioButton_destinataire->isChecked())
    {
        ui->tableView_colis->setModel(tmpcolis.trier("ID_PARTENAIRE",ui->AD->currentText()));
    }
    else if(ui->radioButton_expediteur->isChecked())
    {
        ui->tableView_colis->setModel(tmpcolis.trier("ID_CLIENT",ui->AD->currentText()));
    }
    else if(ui->radioButton_dateL->isChecked())
    {
        ui->tableView_colis->setModel(tmpcolis.trier("DATE_LIVRAISON",ui->AD->currentText()));
    }
}

void MainWindow::on_lineEdit_recherche_colis_textChanged(const QString &arg1)
{
    ui->tableView_colis->setModel(tmpcolis.recherche_avancee(arg1));
}

void MainWindow::on_pushButton_export_partenaires_clicked()
{
click->play();
    tmp_partenaires.imprimerpdf(ui->tableView_part);

}

void MainWindow::on_pushButton_supp_Partenaires_clicked()
{
click->play();
    QItemSelectionModel *select = ui->tableView_part->selectionModel();

    QString n =select->selectedRows(0).value(0).data().toString();
    if(tmp_partenaires.supprimer(n))
    {
        ui->tableView_part->setModel(tmp_partenaires.afficher());
        ui->statusbar->showMessage("partenaire supprimé");
    }
}

void MainWindow::on_pushButton_Statistiques_partenaires_clicked()
{
click->play();
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->statPartenaires->setBackground(QBrush(gradient));
    QCPBars *test= new QCPBars(ui->statPartenaires->xAxis, ui->statPartenaires->yAxis);
    test->setAntialiased(false);
    test->setStackingGap(1);
    //test->setName("Nombre de commandes");
    test->setPen(QPen(QColor(255,67,27)));
    test->setBrush(QColor(255,67,27));
    //axes des x
    QVector<double> nb;
    QVector<QString> nom;
    nb <<1<<2<<3<<4 ;
    nom <<"alimentaire"<<"esthétique"<<"vestimentaire"<<"divers";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(nb,nom);
    ui->statPartenaires->xAxis->setTicker(textTicker);
    ui->statPartenaires->xAxis->setTickLabelRotation(60);
    ui->statPartenaires->xAxis->setSubTicks(false);
    ui->statPartenaires->xAxis->setTickLength(0, 4);
    ui->statPartenaires->xAxis->setRange(0, 8);
    ui->statPartenaires->xAxis->setBasePen(QPen(Qt::white));
    ui->statPartenaires->xAxis->setTickPen(QPen(Qt::white));
    ui->statPartenaires->xAxis->grid()->setVisible(true);
    ui->statPartenaires->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->statPartenaires->xAxis->setTickLabelColor(Qt::white);
    ui->statPartenaires->xAxis->setLabelColor(Qt::white);
    //axe des y
    ui->statPartenaires->yAxis->setRange(0,30);
    ui->statPartenaires->yAxis->setPadding(5); // a bit more space to the left border
    ui->statPartenaires->yAxis->setBasePen(QPen(Qt::white));
    ui->statPartenaires->yAxis->setTickPen(QPen(Qt::white));
    ui->statPartenaires->yAxis->setSubTickPen(QPen(Qt::white));
    ui->statPartenaires->yAxis->grid()->setSubGridVisible(true);
    ui->statPartenaires->yAxis->setTickLabelColor(Qt::white);
    ui->statPartenaires->yAxis->setLabelColor(Qt::white);
    ui->statPartenaires->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->statPartenaires->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    //njibou el data
    QVector<double> testData=tmp_partenaires.getData();

    test->setData(nb,testData);
    ui->statPartenaires->legend->setVisible(false);
    ui->statPartenaires->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->statPartenaires->legend->setBrush(QColor(255, 255, 255, 100));
    ui->statPartenaires->legend->setBorderPen(Qt::NoPen);

    QFont legendFont = font();
    legendFont.setPointSize(20);
    ui->statPartenaires->legend->setFont(legendFont);
    ui->statPartenaires->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_contract_colis_clicked()
{click->play();
    static int turn=1;
    if (turn==1)
    {
        contract_animation->start();
        ui->contract_colis->setText("Expand");
    }
    else
    {
        expand_animation->start();
        ui->contract_colis->setText("Contract");
    }
    turn*=-1;
}

void MainWindow::on_pushButton_recherche_partenaires_clicked()
{
click->play();
    QString NOM = ui->lineEdit_recherche__partenaires->text();
    QSqlQueryModel *test=tmp_partenaires.chercher_partenaire(NOM);
    if (ui->pushButton_recherche_partenaires->isChecked()){
        ui->pushButton_recherche_partenaires->setText("En cours");

        if(test != nullptr)
        {
            QMessageBox::information(nullptr, QObject::tr("chercher un colis"),
                                     QObject::tr("colis trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_part->setModel(test);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher un partenaire"),
                                  QObject::tr("Erreur , partenaire introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_part->setModel(test);
        }}
    else
    {
        ui->pushButton_recherche_partenaires->setText("Recherche");
        ui->tableView_part->setModel(tmp_partenaires.afficher());

    }
}



void MainWindow::on_deconnexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_RecherchePub_clicked()
{
    click->play();
    ui->tableViewPub->setModel(ptmp.afficher(  ));
    int id= ui->RecherchePub_2->text().toInt();
    ui->tableViewPub->setModel(ptmp.recherche(id));

}

void MainWindow::on_SupprimerPub_clicked()
{
    click->play();
    QItemSelectionModel *select = ui->tableViewPub->selectionModel();

    int id =select->selectedRows(0).value(0).data().toInt();

    if(ptmp.supprimer(id))
    {
        ui->tableViewPub->setModel(ptmp.afficher());
        ui->statusbar->showMessage("publicite supprimé");
    }
}

void MainWindow::on_TriRec_clicked()
{
    click->play();
    ui->tableViewRec->setModel(rtmp.tri());
}

void MainWindow::on_ModifierRec_clicked()
{
    click->play();
    if (ui->ModifierRec->isChecked())
    {
        // ui->pushButton_modifier->setDisabled(true);
        ui->ModifierRec->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("RECLAMATION");
        tableModel->select();
        ui->tableViewRec->setModel(tableModel);
    }
    else
    {
        ui->ModifierRec->setText("Modifier");
        ui->tableViewRec->setModel(rtmp.afficher());

    }
}

void MainWindow::on_SupprimerRec_clicked()
{
    click->play();
    QItemSelectionModel *select = ui->tableViewRec->selectionModel();

    int id =select->selectedRows(0).value(0).data().toInt();

    if(rtmp.supprimer(id))
    {
        ui->tableViewRec->setModel(rtmp.afficher());
        ui->statusbar->showMessage("Reclamation supprimé");
    }
}

void MainWindow::on_Exporter_clicked()
{
    click->play();
    QMessageBox msgBox;

    int y=0;
    QPdfWriter pdf("try.pdf");
    QPainter painter;
    if (!painter.begin(&pdf))
    {
        msgBox.setText("Couldn't write in the file.");
        msgBox.exec();
    }

    QSqlQuery query("SELECT * FROM RECLAMATION");


    while (query.next())
    {
        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"Fiche Reclamation");
        painter.setPen(Qt::black);
        painter.drawText(3000,3500+y,"Identifiant de reclamation:");
        painter.drawText(3000,4000+y,"produit id:");
        painter.drawText(3000,4500+y,"description:");
        painter.drawText(3000,5000+y,"Date d'ajout de reclamation:");

        QString id = query.value(0).toString();
        QString produit_id = query.value(1).toString();
        QString description = query.value(2).toString();
        QString date_a = query.value(3).toString();


        painter.drawText(5200,3500+y,id);
        painter.drawText(5200,4000+y,produit_id);
        painter.drawText(5200,4500+y,description);
        painter.drawText(5200,5000+y,date_a);
        y=y+3000;
        query.next();
    }
    msgBox.setText("The document has been saved.");
    msgBox.exec();

}

void MainWindow::on_StatistiqueRec_clicked()
{
    click->play();
    statistique stat;
    double dag = stat.traite0();
    double dir = stat.traite1();


    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->widget->setBackground(QBrush(gradient));
    // create empty bar chart objects:

    QCPBars *fossil = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    fossil->setAntialiased(false);


    fossil->setStackingGap(1);



    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "les reclamation traite" << "les reclamation non traite" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setTickLabelRotation(60);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 13);
    ui->widget->xAxis->setBasePen(QPen(Qt::white));
    ui->widget->xAxis->setTickPen(QPen(Qt::white));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->widget->yAxis->setRange(0, 10);
    ui->widget->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget->yAxis->setLabel("Nombres des reclamations traite");
    ui->widget->yAxis->setBasePen(QPen(Qt::white));
    ui->widget->yAxis->setTickPen(QPen(Qt::white));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData;

    fossilData  << dag << dir ;
    fossil->setData(ticks, fossilData);

    ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->widget->legend->setFont(legendFont);
}

void MainWindow::on_Play_clicked()
{
    click->play();
    son->play();
    son->setLoops(QSound::Infinite);
}

void MainWindow::on_Mute_clicked()
{
    click->play();
    son->stop();
}

void MainWindow::on_AjouterRec_clicked()
{
    click->play();
    int id=ui->IdRec->text().toInt();
    int produitID=ui->ProduitIdRec->text().toInt();
    QString descrption=ui->DescriptionRec->text();
    QString date = ui->DateRec->text();
    int traite = ui->TraiteRec->text().toInt();
    if(id != 0 && produitID != 0 && descrption !="" && date != "")
    {

        reclamation r(id,produitID,descrption,date,traite);

        qDebug() << "id:" << r.getID();
        qDebug() << "prod id:" << r.getProdID();
        qDebug() << "descrption :" << r.getDescription();
        qDebug() << "Date:" << r.getDate();
        qDebug() << traite;
        if(traite==1 || traite==0)
        {
            bool test=r.ajouter();
            qDebug() << "test :" << test;
            qDebug() << traite;
            if (test)
            {
                ui->tableViewRec->setModel(rtmp.afficher());
                QMessageBox::information(nullptr,QObject::tr("")
                                         ,QObject::tr("Ajout effectué\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
                ui->tableViewRec->setModel(rtmp.afficher());
            }
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("erreur")
                                  ,QObject::tr("Ajout non effectué , Il faut remplir tous les champs\n"
                                                                  "Click Cancel to exit."),QMessageBox::Cancel);
        }

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                              ,QObject::tr("Ajout non effectué , Il faut remplir tous les champs\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_AjouterPub_clicked()
{
    click->play();
    int id=ui->IdPub->text().toInt();
    int duree=ui->DureePub->text().toInt();
    int prix=ui->PrixPub->text().toInt();
    QString date = ui->DatePub->text();
    if(id != 0 && duree !=0 && prix !=0 && date != "")
    {

        publicite p(id,duree,prix,date);

        qDebug() << "id:" << p.getID();
        qDebug() << "duree:" << p.getDuree();
        qDebug() << "prix:" << p.getPrix();
        qDebug() << "Date:" << p.getDate();

        bool test=p.ajouter();
        qDebug() << "test :" << test;
        if (test)
        {
            ui->tableViewPub->setModel(ptmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("")
                                     ,QObject::tr("Ajout effectué\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
        }
    }


    else

    {
        QMessageBox::warning(nullptr,QObject::tr("Erreur de saisie")
                             ,QObject::tr("Erreur de saisie ,Il faut remplir tout les champs\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
    }



}


void MainWindow::on_ModifierPub_clicked()
{
    click->play();
    if (ui->ModifierPub->isChecked())
    {
        // ui->pushButton_modifier->setDisabled(true);
        ui->ModifierPub->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PUBLICITE");
        tableModel->select();
        ui->tableViewPub->setModel(tableModel);
    }
    else
    {
        ui->ModifierPub->setText("Modifier");
        ui->tableViewPub->setModel(ptmp.afficher());

    }
}

void MainWindow::on_StatPub_clicked()
{
    click->play();
    statistique stat;
    double dag = stat.statestique_partie1();
    double dir = stat.statestique_partie2();


    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->widget_2->setBackground(QBrush(gradient));
    // create empty bar chart objects:

    QCPBars *fossil = new QCPBars(ui->widget_2->xAxis, ui->widget_2->yAxis);
    fossil->setAntialiased(false);


    fossil->setStackingGap(1);


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "prix entre 1 et 50" << "prix entre 50 et 100 " ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget_2->xAxis->setTicker(textTicker);
    ui->widget_2->xAxis->setTickLabelRotation(60);
    ui->widget_2->xAxis->setSubTicks(false);
    ui->widget_2->xAxis->setTickLength(0, 4);
    ui->widget_2->xAxis->setRange(0, 13);
    ui->widget_2->xAxis->setBasePen(QPen(Qt::white));
    ui->widget_2->xAxis->setTickPen(QPen(Qt::white));
    ui->widget_2->xAxis->grid()->setVisible(true);
    ui->widget_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget_2->xAxis->setTickLabelColor(Qt::white);
    ui->widget_2->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->widget_2->yAxis->setRange(0, 10);
    ui->widget_2->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget_2->yAxis->setLabel("Les prix du publicite");
    ui->widget_2->yAxis->setBasePen(QPen(Qt::white));
    ui->widget_2->yAxis->setTickPen(QPen(Qt::white));
    ui->widget_2->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget_2->yAxis->grid()->setSubGridVisible(true);
    ui->widget_2->yAxis->setTickLabelColor(Qt::white);
    ui->widget_2->yAxis->setLabelColor(Qt::white);
    ui->widget_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData;

    fossilData  << dag << dir ;
    fossil->setData(ticks, fossilData);

    ui->widget_2->legend->setVisible(true);
    ui->widget_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget_2->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget_2->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->widget_2->legend->setFont(legendFont);
}

void MainWindow::on_RechercheRec_clicked()
{
    click->play();
    ui->tableViewRec->setModel(rtmp.afficher(  ));
    int id= ui->RechercheRec_2->text().toInt();
    ui->tableViewRec->setModel(rtmp.recherche(id));

}

void MainWindow::on_login_clicked()
{
click->play();
    QString identifiant = ui->lineEdit_login->text();
    QString mdp = ui->lineEdit_password->text();
    QSound::play("C:/Users/legion/Desktop/salma/Smart_Home_Delivery_2A1/delivaro/sound.wav");
    if (identifiant == "salma" && mdp== "salma1"){

        ui->stackedWidget->setCurrentIndex(1);
        QMessageBox::information(this,"Bienvenue","Mot de passe et identifiant correctes");
        QSound::play("C:/Users/legion/Desktop/salma/Smart_Home_Delivery_2A1/delivaro/sound.wav");

    }
    else if (identifiant == "abdou" && mdp== "abdou1"){

        ui->stackedWidget->setCurrentIndex(1);
        QMessageBox::information(this,"Bienvenue","Mot de passe et identifiant correctes");
        QSound::play("C:/Users/legion/Desktop/salma/Smart_Home_Delivery_2A1/delivaro/sound.wav");

    }
    else if (identifiant == "yessine" && mdp== "yessine1"){
        //BEGIN TEST
        //playsound();

        ui->stackedWidget->setCurrentIndex(1);
        QMessageBox::information(this,"Bienvenue","Mot de passe et identifiant correctes");
        QSound::play("C:/Users/legion/Desktop/salma/Smart_Home_Delivery_2A1/delivaro/sound.wav");


    }
    else{

        QMessageBox::information(this,"Warning","Mot de passe ou identifiant incorrectes");
    }
}


void MainWindow::on_gestionpartenaires_clicked()
{
click->play();
    ui->stackedWidget->setCurrentIndex(2);

    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_gestioncolis_clicked()
{
click->play();
    ui->stackedWidget->setCurrentIndex(2);

    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_gestionpubreclamation_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_retour_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour2_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_retourmenu_clicked()
{click->play();
    ui->stackedWidget->setCurrentIndex(1);

}
void MainWindow::on_passwordcheck_toggled(bool checked)
{
click->play();
    if(checked){
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
    }
    else
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_pushButton_envoyerbonC_clicked()
{
click->play();
    email email_window(this);
    email_window.exec();
    email_window.show();
}


void MainWindow::on_radioButton_modeNuit_toggled(bool)
{
    this->setStyleSheet("font: 8pt \"Pacifico\";"
                            "background-color: rgb(43, 40, 38);"
                            "color: #FFFFFF;");


        QList<QPushButton *> butts = this->findChildren<QPushButton *>();

        for (int i=0; i<butts.size();i++)
        {
            butts.at(i)->setStyleSheet("QPushButton { background-color: #444444; }");
        }


        QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

        for (int i=0; i<tabs.size();i++)
        {
            tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: rgb(68, 68, 68);}"
                                                        "color: #FFFFFF;");
        }

        //        QList<QTableView *> tabviews = this->findChildren<QTableView *>();

        //        for (int i=0; i<tabviews.size();i++)
        //        {
        //            tabs.at(i)->setStyleSheet("QTableView::tab { background-color: rgb(68, 68, 68);}");
        //       }



}

void MainWindow::on_radioButton_modeJour_toggled(bool)
{
    this->setStyleSheet(" background-color:#FFEEE7; ");

        QList<QPushButton *> butts = this->findChildren<QPushButton *>();

        for (int i=0; i<butts.size();i++)
        {
            butts.at(i)->setStyleSheet("QPushButton { background-color:#e86054;}");

        }

}

void MainWindow::on_alerte_clicked()
{   click->play();
    if(ui->alerte->isChecked())
    {
        buzzer="yes";
        const char * p1= buzzer.toStdString().c_str();
        A.write_to_arduino(p1);}
    else
    {
        buzzer="no";
        const char * p2= buzzer.toStdString().c_str();
        A.write_to_arduino(p2);
        ui->alerte->setDisabled(true);

    }
}

void MainWindow::on_radioButton_anglais_toggled(bool checked)
{
    translator->load("C:/Users/legion/Desktop/delivaro(salma+abdou)/samrt_home_delivery/samrt_home_delivery_en");

            qApp->installTranslator(translator);
            ui->retranslateUi(this);

}

void MainWindow::on_radioButton_francais_toggled(bool checked)
{
    translator->load("C:/Users/legion/Desktop/delivaro(salma+abdou)/samrt_home_delivery/samrt_home_delivery_fr");

            qApp->installTranslator(translator);
            ui->retranslateUi(this);
}

void MainWindow::on_deconnexMenu_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}
