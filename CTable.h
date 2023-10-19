#ifndef CTABLE_H
#define CTABLE_H

#include <string>

#define CTABLE_DEFAULT_NAME "default"
#define CTABLE_DEFAULT_LENGTH 7

class CTable {
public:
    CTable();

    CTable(std::string sName, int iTableLen);

    CTable(CTable& pcOther);

    ~CTable();

    void vSetName(std::string sName);

    bool bSetNewSize(int iTableLen);

    int iGetSize();

    CTable* pcClone();

private:
    void vCopyTableFrom(int* piTable, int iTableLen);

    void vSendMessage(const char* sTitle);

    std::string s_name;

    int* pi_table;
    int i_table_length;

};


#endif //CTABLE_H
