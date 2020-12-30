#ifndef DELIVARO_H
#define DELIVARO_H

#include <QMainWindow>
#include "partenaire.h"
#include "colis.h"
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>
#include "reclamation.h"
#include "publicite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class delivaro; }
QT_END_NAMESPACE

class delivaro : public QMainWindow
{
    Q_OBJECT

public:
    delivaro(QWidget *parent = nullptr);
    ~delivaro();



private slots:
    void on_deconnexion_clicked();
    void on_pushButton_ajouterP_clicked();

    void on_pushButton_ajouterColis_clicked();

    void on_pushButton_modifier_Partenaires_clicked();

    void on_pushButton_modifier_colis_clicked();

    void on_pushButton_supprimer_colis_clicked();

    void on_pushButton_recherche_colis_clicked();



    void on_pushButton_export_colis_clicked();

    void on_pushButton_tabcolis_clicked();

    void on_pushButton_tabpartenaires_clicked();

   // void on_pushButton_StatistiquesColis_clicked();

    void on_pushButton_triColis_clicked();

    void on_lineEdit_recherche_colis_textChanged(const QString &arg1);

    void on_pushButton_export_partenaires_clicked();

    void on_pushButton_supp_Partenaires_clicked();

    void on_pushButton_Statistiques_partenaires_clicked();

    void on_contract_colis_clicked();

    void on_pushButton_recherche_partenaires_clicked();



    void on_RecherchePub_clicked();

    void on_SupprimerPub_clicked();

    void on_TriRec_clicked();

    void on_ModifierRec_clicked();

    void on_SupprimerRec_clicked();

    void on_Exporter_clicked();

    void on_StatistiqueRec_clicked();

    void on_Play_clicked();

    void on_Mute_clicked();

    void on_AjouterRec_clicked();

    void on_AjouterPub_clicked();

    void on_ModifierPub_clicked();

    void on_StatPub_clicked();

    void on_RechercheRec_clicked();

    void on_login_clicked();

    void on_gestionpartenaires_clicked();

    void on_gestioncolis_clicked();

    void on_gestionpubreclamation_clicked();

    void on_retour_clicked();

    void on_retour2_clicked();

    void on_partenaires_clicked();

    void on_retourmenu_clicked();

private:
    Ui::delivaro *ui;
    Colis tmpcolis;
    partenaire tmp_partenaires;
        QRegExp nom_regex;
        QRegExp identifiant_regex;
        QRegExp nombre_commandes_regex;
        QRegExp type_produit_regex;
        QPropertyAnimation *contract_animation;
          QPropertyAnimation *expand_animation;

          reclamation rtmp;
          publicite ptmp;
          QSound *son;
          QSound *click;

};
#endif // DELIVARO_H