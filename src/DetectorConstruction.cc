#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4MaterialTable.hh"
#include "G4VSolid.hh"
#include "G4Orb.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4UserLimits.hh"
#include "G4RunManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4ios.hh"
#include "math.h"
#include "G4TransportationManager.hh"
#include "G4UserLimits.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

//extern std::ofstream outbrick;
extern G4double Det_level[52],ll1[52],ll2[52];

extern G4int  nev;
extern FILE *fp2;
extern FILE *fp3;
extern FILE *fp5;

DetectorConstruction::DetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{
    DestroyMaterials();
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
   
        ConstructMaterials();
    //World
    G4VSolid* worldSolid = new G4Box("worldBox",10.0*m,10.0*m,5.0*m);
    G4LogicalVolume* worldLogical= new G4LogicalVolume(worldSolid,Air,"worldLogical");
    G4VPhysicalVolume* worldPhysical= new G4PVPlacement(0,G4ThreeVector(),worldLogical,"worldPhysical",0,0,0);
    int i;
//    double dl=6.0, dli;
      double dl=2.0, dli;
    
//     double pb=1.0*cm; 
   
     double pla=4.0*cm;
     
     double fer=1.0*cm;
//     double fer=5.0*cm;     
     
     double csi=4.0*cm;
      
     
  
    G4double hall_x=50.0*cm;
    G4double hall_y=50.0*cm;
    G4double hall_z=1.0*cm;
//    G4double hall_z=30.0*cm;    
    
    G4double hall_zpl=2.0*cm;

//**********************************************1*************************************************** 

    G4VSolid* leadSolid1 = new G4Box("LeadPlate1",hall_x,hall_y,hall_z);
    G4LogicalVolume* leadLogical1 = new G4LogicalVolume(leadSolid1,Fe,"leadLogical1");
//    G4VSolid* PlasSolid1 = new G4Box("PlasPlate1",hall_x,hall_y,hall_zpl);
//    G4LogicalVolume* PlasLogical1  = new G4LogicalVolume(PlasSolid1,Plast,"PlasLogical1");


    for(i=0; i<=51;i++){
//   ll1[i]=(2.+i*6.0)*cm;
//   ll2[i]=(6.+i*6.0)*cm;   
   ll1[i]=i*2.0*cm;
//   ll2[i]=(6.+i*6.0)*cm;   

//    G4cout <<  " ll1[i]  " <<ll1[i]/cm <<  " ll2[i]  " <<ll2[i]/cm      << G4endl;
    G4cout <<  " ll1[i]   " <<ll1[i]/cm   <<" cm " << G4endl;
                      }


    for(i=0; i<50;i++){ 
//       for(i=0; i<10;i++){
//   i=0;
   dli=(dl*i)*cm;

    G4cout <<  " fer+dli =  " <<(fer+dli)/cm   <<" cm " << G4endl;   
   
    G4VPhysicalVolume* leadPhysical1= new G4PVPlacement(0,G4ThreeVector(0.0,0.0,fer+dli),leadLogical1,
                  "leadPhysical1",worldLogical,0,i);

//    G4VPhysicalVolume* PlasPhysical1= new G4PVPlacement(0,G4ThreeVector(0.0,0.0,pla+dli),PlasLogical1,
//                    "PlasPhysical1",worldLogical,0,i);
                      }


    G4cout << G4endl << "The geometrical tree defined are : " << G4endl << G4endl;
    DumpGeometricalTree(worldPhysical);



    
    return worldPhysical;
}




void DetectorConstruction::ConstructMaterials()
{

  G4double a;
  G4double z;
  G4double density;
  G4String name;
  G4String symbol;
  G4double fractionmass;
  G4int ncomponents;

//  G4int nElem;
  // elements for mixtures and compounds
  a = 1.00795*g/mole;
  G4Element* elH = new G4Element(name="Hydrogen", symbol="H", z=1., a);
  a = 4.0026*g/mole;
  G4Element* elHe = new G4Element(name="Helium", symbol="He", z=2., a);  
  a = 12.0108*g/mole;
  G4Element* elC = new G4Element(name="Carbon", symbol="C", z=6., a);
  a = 14.0067*g/mole;
  G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z=7., a);
  a = 15.9994*g/mole;
  G4Element* elO = new G4Element(name="Oxigen", symbol="O", z=8., a);
  a = 20.179*g/mole;
  G4Element* elS = new G4Element(name="Sulfur", symbol="S", z=16., a);
  a = 107.900*g/mole;
  G4Element* elAg = new G4Element(name="Silver", symbol="Ag", z=47., a);  
  a = 79.900*g/mole;
  G4Element* elBr = new G4Element(name="Bromine", symbol="Br", z=35., a);   
  a = 126.900*g/mole;
  G4Element* elI = new G4Element(name="Iodine", symbol="I", z=53., a);   


//  G4double pk=1.0e-10;
/*
  a=1.010*g/mole;
  density=1.0e-10*g/cm3;
  vac= new G4Material(name="Vac",z=1.0,a,density);
 */
  a=207.19*g/mole;
  density= 11.35*g/cm3;
  Pb=new G4Material(name="Pb",z=82.0,a,density);
  
  
  a=55.845*g/mole;
  density= 7.874*g/cm3;
  Fe=new G4Material(name="Fe",z=26.0,a,density);
  
  

  Emul = new G4Material(name="Emul", density=3.816*g/cm3, ncomponents=8);
  Emul->AddElement(elAg , fractionmass=1.809/3.816);
  Emul->AddElement(elBr , fractionmass=1.332/3.816);
  Emul->AddElement(elI  , fractionmass=0.012/3.816);
  Emul->AddElement(elC  , fractionmass=0.276/3.816);
  Emul->AddElement(elH  , fractionmass=0.054/3.816);
  Emul->AddElement(elO  , fractionmass=0.252/3.816);
  Emul->AddElement(elN  , fractionmass=0.074/3.816);
  Emul->AddElement(elS  , fractionmass=0.007/3.816);

  //Plastic for emulsion base

  Plast = new G4Material(name="Plast", density=1.032*g/cm3, ncomponents=2);
  Plast->AddElement(elC, fractionmass=92.3*perCent);
  Plast->AddElement(elH, fractionmass= 7.7*perCent);

  Air= new G4Material(name="Air",density,ncomponents=2);
  Air->AddElement(elN, fractionmass=14.0067*7.04648e-5/1.30309);
  Air->AddElement(elO, fractionmass=15.9994*7.37857e-4/1.30309);
    

    G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;

    
}

void DetectorConstruction::DestroyMaterials()
{
  // Destroy all allocated elements and materials
  size_t i;
  G4MaterialTable* matTable = (G4MaterialTable*)G4Material::GetMaterialTable();
  for(i=0;i<matTable->size();i++)
  { delete (*(matTable))[i]; }
  matTable->clear();
  G4ElementTable* elemTable = (G4ElementTable*)G4Element::GetElementTable();
  for(i=0;i<elemTable->size();i++)
  { delete (*(elemTable))[i]; }
  elemTable->clear();
}

void DetectorConstruction::DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth)
{
  for(int isp=0;isp<depth;isp++)
  { G4cout << "  "; }
  G4cout << aVolume->GetName() << "[" << aVolume->GetCopyNo() << "] "
         << aVolume->GetLogicalVolume()->GetName() << " "
         << aVolume->GetLogicalVolume()->GetNoDaughters() << " "
         << aVolume->GetLogicalVolume()->GetMaterial()->GetName();

  G4cout << G4endl;
  for(int i=0;i<aVolume->GetLogicalVolume()->GetNoDaughters();i++)
  { DumpGeometricalTree(aVolume->GetLogicalVolume()->GetDaughter(i),depth+1); }
}
