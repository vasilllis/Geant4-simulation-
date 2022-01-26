#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"

#include "DetectorConstruction.hh"
#include "G4Electron.hh"
#include "G4Proton.hh"
#include "HistoManager.hh"


//extern std::ofstream outbrick;
extern G4double Det_level[52],ll1[52],ll2[52];
extern G4double Ekin_rand;

extern G4int  Nev;
extern FILE *fp2;
extern FILE *fp3;
extern FILE *fp5;

int i,nsob,nmutau,npipi,npi0,ndd,nsobn,nsobna,partid;
double ptot,ptotcl,Ekin;
int partid_nu_o, kNC=0; 
double Etot_nu_o, Ekin_nu_o, px_nu_o, py_nu_o, pz_nu_o;
int partid_nu; 

 auto particleTable = G4ParticleTable::GetParticleTable();  

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction* det)
:G4VUserPrimaryGeneratorAction(),fParticleGun(0),fDetector(det)
{
//  auto particleTable = G4ParticleTable::GetParticleTable(); 

  fParticleGun  = new G4ParticleGun(1);

//  fParticleGun->SetParticleDefinition(G4MuonMinus::MuonMinus()); 
  fParticleGun->SetParticleDefinition(particleTable->FindParticle("mu-"));

  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(1.*GeV);


G4cout<<"PrimaryGeneratorAction: particleName=mu-  "<<G4endl;

    
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{   
//  G4cout<<"PrimaryGeneratorAction"<<G4endl;


    double MyX,MyY,MyZ,randmax;
    double Energy,PX,PY,PZ;
    double PX1, PY1;
//   int n31;
    int evt;


// startofevent: G4cout<<" startofevent  "<<G4endl;

//  G4cout<<"PrimaryGeneratorAction "<<G4endl;

    randmax= 2.0*1024.0*1024.0*1024.0;
    MyX=0.05*rand()/randmax; //in cube 0.05 mm*0.05*0.05
    MyY=0.05*rand()/randmax;
    MyZ=0.05*rand()/randmax;

    MyX=0.001*mm;
    MyY=0.001*mm;
    MyZ=0.001*mm;


//fprintf(fpp,"%lf %lf %lf\n",MyX,MyY,MyZ);
//    fclose(fpp);

    G4double MyParticleEnergy;
    
    const G4int MyEventID= anEvent->GetEventID();
    evt= MyEventID;
    Nev= MyEventID;

  partid==13;





    fParticleGun->SetParticlePosition(G4ThreeVector(MyX*mm,MyY*mm,MyZ*mm));

     
if(partid==13)    
    fParticleGun->SetParticleDefinition(particleTable->FindParticle("mu-"));   //    "mu-"


if(partid==111)    
fParticleGun->SetParticleDefinition(particleTable->FindParticle("pi0")); //"pi0"

if(partid==2212)
fParticleGun->SetParticleDefinition(particleTable->FindParticle("pi+"));   //"pi+"    

if(partid==-211)    
fParticleGun->SetParticleDefinition(particleTable->FindParticle("pi-"));   //"pi-"

if(partid==2212)    
 fParticleGun->SetParticleDefinition(particleTable->FindParticle("proton")); //"proton"


// Energy=150.0*GeV; 
// Energy=10.0*GeV; 
// Energy=1.0*GeV;  
//   Energy=20.0*GeV;   
 //Energy=30.0*GeV;     
// Energy=50.0*GeV;       
//  Energy=80.0*GeV;       
// Energy=100.0*GeV;       

Ekin=10.0+140.0*rand()/randmax;
Energy=Ekin*GeV;
Ekin_rand=Ekin*GeV;


 PX=0.0;
 PY=0.0;
 PZ=1.0;
// particleGun->SetParticleDefinition(G4ParticleTable->FindParticle("mu-"));
  
    fParticleGun->SetParticleEnergy(Energy);

  MyParticleEnergy= fParticleGun->GetParticleEnergy();
//    G4cout<<" &&&&&   PRIMARY PARTICLE ENERGY "<<  MyParticleEnergy <<G4endl;
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(PX,PY,PZ));    
    fParticleGun->GeneratePrimaryVertex(anEvent);


//a31    par= GenerateEvent(MyEventID+1);
   
//a31    n31=par->ndpart; 
//        fprintf(fp0,"EventID= %d \n",evt);     
//        fprintf(fp2,"EventID= %d \n",evt);
 
// endofevent: G4cout<<" endofevent  "<<G4endl;


//    MyParticleEnergy= particleGun->GetParticleEnergy();
//    G4cout<<"end of ev PRIMARY PARTICLE ENERGY "<<MyParticleEnergy/GeV<<G4endl;
    
}

