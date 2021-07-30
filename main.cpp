#include <iostream>
#include "Engine.h"


int main(int argc, char **argv) {



    try {
        if (argc!=3) throw -1;
        Engine edge(argv[1], argv[2]);
        edge.prepareUI();
    }
    catch(int err){
        cout << "WRONG FILE INPUT IN TERMINAL. PLEASE PROVIDE: ./a.out ./pathOfMap ./pathOfBinaryFile\n";
        exit(err);
    }

    return 0;
}
