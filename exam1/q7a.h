typedef struct { 
  int type;        // one of the above type codes
  int startIndex;  // if array, starting index
  int endIndex;    //           ending index
  int baseType;    //           base type (one of above codes) 
  bool entireVar;  // If entire variable or not (A vs A[5] => True vs False)

  // Vector to hold each variable in procedure
  vector<SYMBOL_TABLE_ENTRY*> procedure_list;
  // If pass by reference
  bool pass_by_reference;

} TYPE_INFO;

/*
When a procedure is used, we'd have to go through the procedure_list
vector and add each element from it to the symbol table.
If the value is pass by reference (ie, pass_by_reference is true),
then we can skip it, since the value should be in a previous scope.
*/

class SYMBOL_TABLE_ENTRY {
private:
  // Member variables
  string name;
  TYPE_INFO typeInfo;  

public:
  // Rest of class

  // Procedure list
  SYMBOL_TABLE_ENTRY(const string theName, 
                     const TYPE_INFO info,
                     const bool pass_by_reference) {
    name = theName;
    typeInfo.type = info.type;
    typeInfo.startIndex = info.startIndex;
    typeInfo.endIndex = info.endIndex;
    typeInfo.baseType = info.baseType;
    typeInfo.pass_by_reference = pass_by_reference;
  }

  // Rest of class
};