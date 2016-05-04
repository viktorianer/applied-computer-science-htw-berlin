int erfasse_ganze_zahl (char *ausgabetext, int min, int max);
double erfasse_gleitkomma_zahl (char *ausgabetext, double min, double max);

void erfasse_zeichenkette(char *ausgabetext, char zeichenkette[], int laenge);
signed char antwort_ja_oder_nein (char *ausgabetext, char wahrheitswert, char unwahrheitswert);

//Ganzzahlige C-Datentypen bei diesem Compiler
//Datentyp            Wertebereich
//signed char         {                 -128 , ... ,                 127 }
//short               {               -32768 , ... ,               32767 }
//int                 {          -2147483648 , ... ,          2147483647 }
//long                {          -2147483648 , ... ,          2147483647 }
//long long           { -9223372036854775808 , ... , 9223372036854775807 }
//Datentyp            Wertebereich
//unsigned char       { 0 , ... ,                  255 }
//unsigned short      { 0 , ... ,                65535 }
//unsigned int        { 0 , ... ,           4294967295 }
//unsigned long       { 0 , ... ,           4294967295 }
//unsigned long long  { 0 , ... , 18446744073709551615 }
//Datentyp            Wertebereich
//signed char         { -128 , ... , 127 }
//unsigned char       {    0 , ... , 255 }
//char                { -128 , ... , 127 }
//float             FLT_MIN        =  1.17549435082228750797E-38
//                  FLT_MAX        =  3.40282346638528859812E+38
//                  FLT_EPSILON    =  1.19209289550781250000E-07
//                  FLT_DIG        =  6
//double            DBL_MIN        =  2.22507385850720138309E-308
//                  DBL_MAX        =  1.79769313486231570815E+308
//                  DBL_EPSILON    =  2.22044604925031308085E-16
//                  DBL_DIG        =  15
//long double       LDBL_MIN       =  3.36210314311209350626E-4932
//                  LDBL_MAX       =  1.18973149535723176502E+4932
//                  LDBL_EPSILON   =  1.08420217248550443401E-19
//                  LDBL_DIG       =  18
