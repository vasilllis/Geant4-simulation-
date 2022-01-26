#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"

class G4Orb;
class G4Torus;
class G4Box;
class G4VPhysicalVolume;
class G4Material;
class G4VisAttributes;
class DetectorConstMessenger;
class G4UserLimits;

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
    DetectorConstruction();
    virtual ~DetectorConstruction();
     
    public:
    virtual G4VPhysicalVolume* Construct();
    G4VPhysicalVolume* worldPhysical;    

    G4VPhysicalVolume* leadPhysical1;


    G4VPhysicalVolume* PlasPhysical1;


    
    G4Material* Air;
    G4Material* Pb;
    G4Material* Fe;    
    G4Material* Emul;
    G4Material* Plast;        
    
    private:
    void ConstructMaterials();
    void DestroyMaterials();
    void DumpGeometricalTree(G4VPhysicalVolume* aVolume,G4int depth=0);
    DetectorConstMessenger* messenger;
//    G4Material* vac;
//    G4Material* Pb;
//    G4Material* Em;
    G4UserLimits *stepLimits;
};
