#include <iostream>
#include "CTable.h"


CTable::CTable() {
    s_name = CTABLE_DEFAULT_NAME;
    table = new int[CTABLE_DEFAULT_LENGTH];
    i_table_len = CTABLE_DEFAULT_LENGTH;

    vSendMessage("bezp: ");
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    table = new int[iTableLen];
    i_table_len = iTableLen;

    vSendMessage("parametr: ");
}

CTable::CTable(CTable& pcOther) {
    s_name = pcOther.s_name + "_copy";

    vSendMessage("kopiuj: ");

    table = new int[pcOther.i_table_len];
    i_table_len = pcOther.i_table_len;

    vCopyTableFrom(pcOther.table, i_table_len);
}

CTable::~CTable() {
    vSendMessage("usuwam: ");

    delete table;
    table = NULL;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 0) {
        return false;
    }

    int* new_table = new int[iTableLen];
    int min_length = (i_table_len < iTableLen) ? i_table_len : iTableLen;

    std::copy(table, table + min_length, new_table);
   
    std::cout << "rozmiar stary : " << iGetSize() << std::endl;;
    delete table;
    table = new_table;
    i_table_len = iTableLen;
    std::cout << "rozmiar nowy : " << iGetSize() << std::endl;;
    return true;
}

int CTable::iGetSize() {
    return i_table_len;
}


CTable* CTable::pcClone() {
    return new CTable(*this);

}

void CTable::vCopyTableFrom(int* piTable, int iTableLen) {
    std::copy(piTable, piTable + iTableLen, table);

}

void CTable::vSendMessage(const char* sTitle) {
    std::cout << sTitle << ": '" << s_name << std::endl;;
}

#include "CTable.h"
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
    CTable copiedTable = originalTable; // Kopiowanie za pomoc¹ konstruktora kopiuj¹cego
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