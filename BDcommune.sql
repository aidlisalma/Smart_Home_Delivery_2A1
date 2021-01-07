--------------------------------------------------------
--  Fichier cr�� - jeudi-janvier-07-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table CLIENTS
--------------------------------------------------------

  CREATE TABLE "CLIENTS" 
   (	"CIN" VARCHAR2(20 CHAR), 
	"NOM" VARCHAR2(20 CHAR), 
	"PRENOM" VARCHAR2(20 CHAR), 
	"ADRESSE" VARCHAR2(20 CHAR)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COLIS
--------------------------------------------------------

  CREATE TABLE "COLIS" 
   (	"NUM_COLIS" NUMBER, 
	"DATE_LIVRAISON" DATE, 
	"ADRESSE" VARCHAR2(20 CHAR), 
	"ID_PARTENAIRE" VARCHAR2(20 CHAR), 
	"ID_CLIENT" VARCHAR2(20 CHAR)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DEPARTEMENT
--------------------------------------------------------

  CREATE TABLE "DEPARTEMENT" 
   (	"ID" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"FICHE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYES
--------------------------------------------------------

  CREATE TABLE "EMPLOYES" 
   (	"MATRICULE" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE" DATE, 
	"TELEPHONE" NUMBER, 
	"MAIL" VARCHAR2(20 BYTE), 
	"PASSWORD" VARCHAR2(20 BYTE), 
	"COLUMN3" VARCHAR2(20 BYTE), 
	"COLUMN4" VARCHAR2(20 BYTE), 
	"CODE_POSTAL" NUMBER, 
	"VILLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FACTURES
--------------------------------------------------------

  CREATE TABLE "FACTURES" 
   (	"ID" VARCHAR2(20 BYTE), 
	"DATE_FACT" VARCHAR2(20 BYTE), 
	"SOMME" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PARTENAIRES
--------------------------------------------------------

  CREATE TABLE "PARTENAIRES" 
   (	"NOM" VARCHAR2(20 CHAR), 
	"IDENTIFIANT" VARCHAR2(20 CHAR), 
	"NOMBRE_COMMANDES" NUMBER, 
	"TYPE_PRODUIT" VARCHAR2(20 CHAR)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PUBLICITES
--------------------------------------------------------

  CREATE TABLE "PUBLICITES" 
   (	"ID" NUMBER, 
	"PRIX" NUMBER, 
	"DUREE" NUMBER, 
	"DATE_PUB" DATE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RECLAMATION
--------------------------------------------------------

  CREATE TABLE "RECLAMATION" 
   (	"ID" VARCHAR2(20 BYTE), 
	"DATE_RECLAMATION" DATE, 
	"PRODUIT_ID" NUMBER, 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"TRAITE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table TRAJETS
--------------------------------------------------------

  CREATE TABLE "TRAJETS" 
   (	"NUMERO" VARCHAR2(20 BYTE), 
	"PAYS_CHARGEMENT" VARCHAR2(20 BYTE), 
	"PAYS_LIVRAISON" VARCHAR2(20 BYTE), 
	"VILLE_CHARGEMENT" VARCHAR2(20 BYTE), 
	"VILLE_LIVRAISON" VARCHAR2(20 BYTE), 
	"CDP_CHARGEMENT" VARCHAR2(20 BYTE), 
	"CDP_LIVRAISON" VARCHAR2(20 BYTE), 
	"DATE_CHARGEMENT" VARCHAR2(20 BYTE), 
	"DATE_LIVRAISON" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VOITURES
--------------------------------------------------------

  CREATE TABLE "VOITURES" 
   (	"MATRICULE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"CAPACITE" VARCHAR2(20 BYTE), 
	"KILOMETRAGE" NUMBER, 
	"STATUT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into CLIENTS
SET DEFINE OFF;
Insert into CLIENTS (CIN,NOM,PRENOM,ADRESSE) values ('12345678','a','a','a');
REM INSERTING into COLIS
SET DEFINE OFF;
REM INSERTING into DEPARTEMENT
SET DEFINE OFF;
REM INSERTING into EMPLOYES
SET DEFINE OFF;
REM INSERTING into FACTURES
SET DEFINE OFF;
REM INSERTING into PARTENAIRES
SET DEFINE OFF;
REM INSERTING into PUBLICITES
SET DEFINE OFF;
REM INSERTING into RECLAMATION
SET DEFINE OFF;
REM INSERTING into TRAJETS
SET DEFINE OFF;
REM INSERTING into VOITURES
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index RECLAMATION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "RECLAMATION_PK" ON "RECLAMATION" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENTS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "CLIENTS_PK" ON "CLIENTS" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PARTENAIRES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PARTENAIRES_PK" ON "PARTENAIRES" ("IDENTIFIANT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index TRAJETS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TRAJETS_PK" ON "TRAJETS" ("NUMERO") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DEPARTEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "DEPARTEMENT_PK" ON "DEPARTEMENT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COLIS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "COLIS_PK" ON "COLIS" ("NUM_COLIS") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PUBLICITES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PUBLICITES_PK" ON "PUBLICITES" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table RECLAMATION
--------------------------------------------------------

  ALTER TABLE "RECLAMATION" MODIFY ("TRAITE" NOT NULL ENABLE);
  ALTER TABLE "RECLAMATION" ADD CONSTRAINT "RECLAMATION_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "RECLAMATION" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "RECLAMATION" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "RECLAMATION" MODIFY ("PRODUIT_ID" NOT NULL ENABLE);
  ALTER TABLE "RECLAMATION" MODIFY ("DATE_RECLAMATION" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table VOITURES
--------------------------------------------------------

  ALTER TABLE "VOITURES" MODIFY ("MATRICULE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CLIENTS
--------------------------------------------------------

  ALTER TABLE "CLIENTS" MODIFY ("CIN" NOT NULL ENABLE);
  ALTER TABLE "CLIENTS" ADD CONSTRAINT "CLIENTS_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "CLIENTS" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "CLIENTS" MODIFY ("PRENOM" NOT NULL ENABLE);
  ALTER TABLE "CLIENTS" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PUBLICITES
--------------------------------------------------------

  ALTER TABLE "PUBLICITES" ADD CONSTRAINT "PUBLICITES_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "PUBLICITES" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "PUBLICITES" MODIFY ("DATE_PUB" NOT NULL ENABLE);
  ALTER TABLE "PUBLICITES" MODIFY ("PRIX" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COLIS
--------------------------------------------------------

  ALTER TABLE "COLIS" ADD CONSTRAINT "COLIS_PK" PRIMARY KEY ("NUM_COLIS")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "COLIS" MODIFY ("NUM_COLIS" NOT NULL ENABLE);
  ALTER TABLE "COLIS" MODIFY ("ID_CLIENT" NOT NULL ENABLE);
  ALTER TABLE "COLIS" ADD CONSTRAINT "CH_NUMCOLIS" CHECK (10000>NUM_COLIS AND NUM_COLIS>999) ENABLE;
  ALTER TABLE "COLIS" MODIFY ("ID_PARTENAIRE" NOT NULL ENABLE);
  ALTER TABLE "COLIS" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "COLIS" MODIFY ("DATE_LIVRAISON" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table TRAJETS
--------------------------------------------------------

  ALTER TABLE "TRAJETS" ADD CONSTRAINT "TRAJETS_PK" PRIMARY KEY ("NUMERO")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TRAJETS" MODIFY ("NUMERO" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DEPARTEMENT
--------------------------------------------------------

  ALTER TABLE "DEPARTEMENT" ADD CONSTRAINT "DEPARTEMENT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "DEPARTEMENT" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYES
--------------------------------------------------------

  ALTER TABLE "EMPLOYES" MODIFY ("PASSWORD" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYES" MODIFY ("MAIL" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PARTENAIRES
--------------------------------------------------------

  ALTER TABLE "PARTENAIRES" ADD CONSTRAINT "PARTENAIRES_PK" PRIMARY KEY ("IDENTIFIANT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "PARTENAIRES" MODIFY ("TYPE_PRODUIT" NOT NULL ENABLE);
  ALTER TABLE "PARTENAIRES" MODIFY ("NOMBRE_COMMANDES" NOT NULL ENABLE);
  ALTER TABLE "PARTENAIRES" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "PARTENAIRES" MODIFY ("IDENTIFIANT" NOT NULL ENABLE);
  ALTER TABLE "PARTENAIRES" ADD CONSTRAINT "CH_NBCOMM" CHECK ( NOMBRE_COMMANDES>0) ENABLE;
  ALTER TABLE "PARTENAIRES" ADD CONSTRAINT "CH_ID" CHECK (100000000>IDENTIFIANT AND IDENTIFIANT>9999999) ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table COLIS
--------------------------------------------------------

  ALTER TABLE "COLIS" ADD CONSTRAINT "COLIS_FK1" FOREIGN KEY ("ID_PARTENAIRE")
	  REFERENCES "PARTENAIRES" ("IDENTIFIANT") ENABLE;
  ALTER TABLE "COLIS" ADD CONSTRAINT "COLIS_FK2" FOREIGN KEY ("ID_CLIENT")
	  REFERENCES "CLIENTS" ("CIN") ENABLE;