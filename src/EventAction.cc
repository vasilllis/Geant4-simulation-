//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file electromagnetic/TestEm9/src/EventAction.cc
/// \brief Implementation of the EventAction class
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "EventAction.hh"
#include "HistoManager.hh"

#include "G4UImanager.hh"
#include "G4Gamma.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

extern G4int Nev; 
extern G4int nscat;

extern FILE *fp2;
extern FILE *fp3;
extern FILE *fp5;

extern  G4double Det_level[52],ll1[52],ll2[52];
extern  G4double Ekin_rand;



EventAction::EventAction():
  G4UserEventAction(),
  fVerbose(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* event)
{


//  fp2=fopen("tau-trec","a");
// fprintf(fp2,"1:  Begin of EventAction  Nev= %d  Eneutron_summ=%7.6e(GeV)  \n",Nev, Eneutron_summ/GeV);
//  fprintf(fp2,"1:  Begin of EventAction  Nev= %d  SumPartEnKilled=%7.6e(GeV) \n",Nev, SumPartEnKilled/GeV);

  int i;
  
  Nev = event->GetEventID();
  nscat=0;
 
 for(i=0;i<=50;i++) {
 Det_level[i]=0.0;   
                    }  

//fprintf(fp3,"  Start of EventAction \n");


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
 

  int i;     
 Nev = event->GetEventID();
//  fp2=fopen("mu-trec","a");
// fprintf(fp2,"End of EventAction  Nev= %d   \n", Nev);

  fp3=fopen("mu-Endep-levels-10GeV-opt0-0-1cm","a");
//  fp3=fopen("mu-Endep-levels-50GeV-SS-0-1cm","a");
//fprintf(fp3,"  End of EventAction \n");

fprintf(fp3,"\n   %d  ",Nev);

/*
for (i=0; i<=9;i++)                    
  fprintf(fp3,"  %7.6e  ", Det_level[i] );
for (i=10; i<=19;i++)                   
  fprintf(fp3,"  %7.6e  ", Det_level[i] );
for (i=20; i<=29;i++)                   
  fprintf(fp3,"  %7.6e  ", Det_level[i] );
for (i=30; i<=39;i++)                   
  fprintf(fp3,"  %7.6e  ", Det_level[i] );
for (i=40; i<=49;i++)                   
  fprintf(fp3,"  %7.6e  ", Det_level[i] );
*/

  fprintf(fp3," %7.6e  ", Ekin_rand);
for (i=1; i<=49;i++)                   
//for (i=0; i<=10;i++)                   
  fprintf(fp3,"%7.6e  ", Det_level[i] );

//fprintf(fp3,"        \n");
//for (i=0; i<=51;i++)                   
//  fprintf(fp3,"%7.6e  ", ll1[i], ll2[i] );


   fclose(fp3);
//   fclose(fp2);
    
 

  if(fVerbose > 0) {
    G4cout << "EventAction: Event # " << event->GetEventID() 
           << " ended" << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
