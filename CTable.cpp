#include <iostream>
#include "CTable.h"


CTable::CTable() {
    s_name = CTABLE_DEFAULT_NAME;
    pi_table = new int[CTABLE_DEFAULT_LENGTH];
    i_table_length = CTABLE_DEFAULT_LENGTH;

    std::cout << "bezp: '" << s_name << "'" << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    pi_table = new int[iTableLen];
    i_table_length = iTableLen;

    std::cout << "parametr: '" << s_name << "'" << std::endl;

}

CTable::CTable(CTable& pcOther) {
    s_name = pcOther.s_name + "_copy";
    std::cout << "kopiuj: '" << s_name << "'" << std::endl;
    i_table_length = pcOther.i_table_length;
    pi_table = new int[i_table_length];
    for (int i = 0; i < i_table_length; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
}

CTable::~CTable() {

    std::cout << "usuwam: '" << s_name << "'" << std::endl;
    delete pi_table;
    pi_table = NULL;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 0) {
        return false;
    }

    int* pi_new_table = new int[iTableLen];
    int min_length = (i_table_length < iTableLen) ? i_table_length : iTableLen;

    for (int i = 0; i < min_length; i++) {
        pi_new_table[i] = pi_table[i];
    }
    std::cout << "rozmiar stary : " << iGetSize() << std::endl;;
    delete pi_table;
    pi_table = pi_new_table;
    i_table_length = iTableLen;
    std::cout << "rozmiar nowy : " << iGetSize() << std::endl;;
    return true;
}

int CTable::iGetSize() {
    return i_table_length;
}


CTable* CTable::pcClone() {
    return new CTable(*this);

}

//ten zmieni tylko kopie
void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}
//ten dzieki uzyciu wskawnika zmieni wartosc
void v_mod_tab(CTable* pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

int main() {

    CTable staticTable; // Tworzenie obiektu CTable na stosie
    staticTable.vSetName("static");

    CTable* dynamicTable = new CTable; // Tworzenie obiektu CTable na stercie
    dynamicTable -> vSetName("dynamic");
    delete dynamicTable;

    CTable originalTable;
    CTable copiedTable = originalTable; // Kopiowanie za pomocą konstruktora kopiującego
    staticTable.vSetName("copy");

    CTable resizableTable;
    resizableTable.bSetNewSize(10); // Zmiana rozmiaru tablicy na 10
    resizableTable.bSetNewSize(4);
    resizableTable.vSetName("resizeable");

    CTable newTable("newStatic", 15);

    std::cout << "przed v_mod_tab newStatic: " << newTable.iGetSize() << std::endl;;
    v_mod_tab(newTable, 22);
    std::cout << "po v_mod_tab newStatic: " << newTable.iGetSize() << std::endl;;
    std::cout << "przed v_mod_tabnewStatic: " << newTable.iGetSize() << std::endl;;
    v_mod_tab(&newTable, 98);
    std::cout << "po v_mod_tabnewStatic: " << newTable.iGetSize()<< std::endl;;

    

}
