#include<bits/stdc++.h> 
using namespace std;

/*
Use Cases:

Facade: hides complexity
Adapter: provide interaction between complex interfaces 

1. Gaming Engine (Unity, game load (mem, map, assets, game physics,.....))
2. hide complex subsystem

*/

class PowerSupply {
    public:
        void providePower() {
            cout << "Power Supply: providing power..." << endl;
        }
};

class CoolingSystem {
    public:
        void startFans() {
            cout << "Cooling System: fan started..." << endl;
        }
};

class CPU {
    public:
        void initialize() {
            cout << "CPU initalization started..." << endl;
        }
};

class Memory {
    public:
        void selftTest() {
            cout << "Memory: self test passed..." << endl;
        }
};

class HardDrive {
    public:
        void spinUp() {
            cout << "Hard Drive: spin up started..." << endl;
        }
};

class BIOS {
    public:
        void boot(CPU &cpu, Memory &memory) {
            cout << "BIOS: booting CPU and Memory checks..." << endl;
            cpu.initialize();
            memory.selftTest();
        }
};

class OperatingSytem {
    public:
        void load() {
            cout << "Operating System: loading to memory..." << endl;
        }
};

class ComputerFacade {
    private:
        PowerSupply powerSupply;
        CoolingSystem coolingSystem;
        CPU cpu;
        Memory memory;
        HardDrive hardDrive;
        BIOS bios;
        OperatingSytem os;
    
    public:

        void StartComputer() {
            cout << "-----Starting Computer------" << endl;
            powerSupply.providePower();
            coolingSystem.startFans();
            bios.boot(cpu, memory);
            hardDrive.spinUp();
            os.load();
            cout << "----Computer Started Successfully----" << endl;
        }
};

int main() {

    ComputerFacade computer;
    computer.StartComputer();
    return 0;
}