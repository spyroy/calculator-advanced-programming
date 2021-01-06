#include "symtab.h"
#include "scanner.h"
Attributes& Symbol_table::get(string name)
{
    return sym_tab.find(name)->second;
}

void Symbol_table::set(string name, double nv)
{
    if ( sym_tab.find(name) == sym_tab.end() ) 
    {
        // name is not defined
        return;
    } 
    if(!sym_tab.find(name)->second.is_const)
    {
        sym_tab.find(name)->second.value = nv;
    }
    else{
        error("cannot change constant");
    }
}

bool Symbol_table::is_declared(string name)
{
    if ( sym_tab.find(name) == sym_tab.end() ) 
    {
        return false;
    } 
    else 
    {
        return true;
    }
}

void Symbol_table::declare(string name, double nv, bool ic)
{
    Attributes A(nv,ic);
    if ( (sym_tab.find(name) == sym_tab.end()) ) 
    {
        sym_tab.insert({name,A});
    } 
    else 
    {
        return;
    }
}

