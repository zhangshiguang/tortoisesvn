/* Automatically generated.  Do not edit */
/* See the mkopcodec.awk script for details. */
#if !defined(SQLITE_OMIT_EXPLAIN) || !defined(NDEBUG) || defined(VDBE_PROFILE) || defined(SQLITE_DEBUG)
const char *sqlite3OpcodeName(int i){
 static const char *const azName[] = { "?",
     /*   1 */ "MemLoad",
     /*   2 */ "VNext",
     /*   3 */ "Column",
     /*   4 */ "SetCookie",
     /*   5 */ "IfMemPos",
     /*   6 */ "Sequence",
     /*   7 */ "MoveGt",
     /*   8 */ "RowKey",
     /*   9 */ "OpenWrite",
     /*  10 */ "If",
     /*  11 */ "Pop",
     /*  12 */ "VRowid",
     /*  13 */ "CollSeq",
     /*  14 */ "OpenRead",
     /*  15 */ "Expire",
     /*  16 */ "Not",
     /*  17 */ "AutoCommit",
     /*  18 */ "IntegrityCk",
     /*  19 */ "Sort",
     /*  20 */ "Function",
     /*  21 */ "Noop",
     /*  22 */ "Return",
     /*  23 */ "NewRowid",
     /*  24 */ "IfMemNeg",
     /*  25 */ "Variable",
     /*  26 */ "String",
     /*  27 */ "RealAffinity",
     /*  28 */ "VRename",
     /*  29 */ "ParseSchema",
     /*  30 */ "VOpen",
     /*  31 */ "Close",
     /*  32 */ "CreateIndex",
     /*  33 */ "IsUnique",
     /*  34 */ "NotFound",
     /*  35 */ "Int64",
     /*  36 */ "MustBeInt",
     /*  37 */ "Halt",
     /*  38 */ "Rowid",
     /*  39 */ "IdxLT",
     /*  40 */ "AddImm",
     /*  41 */ "Statement",
     /*  42 */ "RowData",
     /*  43 */ "MemMax",
     /*  44 */ "Push",
     /*  45 */ "NotExists",
     /*  46 */ "MemIncr",
     /*  47 */ "Gosub",
     /*  48 */ "Integer",
     /*  49 */ "MemInt",
     /*  50 */ "Prev",
     /*  51 */ "VColumn",
     /*  52 */ "CreateTable",
     /*  53 */ "Last",
     /*  54 */ "IncrVacuum",
     /*  55 */ "IdxRowid",
     /*  56 */ "MakeIdxRec",
     /*  57 */ "ResetCount",
     /*  58 */ "FifoWrite",
     /*  59 */ "Callback",
     /*  60 */ "Or",
     /*  61 */ "And",
     /*  62 */ "ContextPush",
     /*  63 */ "DropTrigger",
     /*  64 */ "DropIndex",
     /*  65 */ "IsNull",
     /*  66 */ "NotNull",
     /*  67 */ "Ne",
     /*  68 */ "Eq",
     /*  69 */ "Gt",
     /*  70 */ "Le",
     /*  71 */ "Lt",
     /*  72 */ "Ge",
     /*  73 */ "IdxGE",
     /*  74 */ "BitAnd",
     /*  75 */ "BitOr",
     /*  76 */ "ShiftLeft",
     /*  77 */ "ShiftRight",
     /*  78 */ "Add",
     /*  79 */ "Subtract",
     /*  80 */ "Multiply",
     /*  81 */ "Divide",
     /*  82 */ "Remainder",
     /*  83 */ "Concat",
     /*  84 */ "IdxDelete",
     /*  85 */ "Negative",
     /*  86 */ "Vacuum",
     /*  87 */ "BitNot",
     /*  88 */ "String8",
     /*  89 */ "MoveLe",
     /*  90 */ "IfNot",
     /*  91 */ "DropTable",
     /*  92 */ "MakeRecord",
     /*  93 */ "Delete",
     /*  94 */ "StackDepth",
     /*  95 */ "AggFinal",
     /*  96 */ "Dup",
     /*  97 */ "Goto",
     /*  98 */ "TableLock",
     /*  99 */ "FifoRead",
     /* 100 */ "Clear",
     /* 101 */ "IdxGT",
     /* 102 */ "MoveLt",
     /* 103 */ "VerifyCookie",
     /* 104 */ "AggStep",
     /* 105 */ "Pull",
     /* 106 */ "SetNumColumns",
     /* 107 */ "AbsValue",
     /* 108 */ "Transaction",
     /* 109 */ "VFilter",
     /* 110 */ "VDestroy",
     /* 111 */ "ContextPop",
     /* 112 */ "Next",
     /* 113 */ "IdxInsert",
     /* 114 */ "Distinct",
     /* 115 */ "Insert",
     /* 116 */ "Destroy",
     /* 117 */ "ReadCookie",
     /* 118 */ "ForceInt",
     /* 119 */ "LoadAnalysis",
     /* 120 */ "Explain",
     /* 121 */ "IfMemZero",
     /* 122 */ "OpenPseudo",
     /* 123 */ "OpenEphemeral",
     /* 124 */ "Null",
     /* 125 */ "Real",
     /* 126 */ "HexBlob",
     /* 127 */ "Blob",
     /* 128 */ "MemStore",
     /* 129 */ "Rewind",
     /* 130 */ "MoveGe",
     /* 131 */ "VBegin",
     /* 132 */ "VUpdate",
     /* 133 */ "VCreate",
     /* 134 */ "MemMove",
     /* 135 */ "MemNull",
     /* 136 */ "Found",
     /* 137 */ "NullRow",
     /* 138 */ "ToText",
     /* 139 */ "ToBlob",
     /* 140 */ "ToNumeric",
     /* 141 */ "ToInt",
     /* 142 */ "ToReal",
  };
  return azName[i];
}
#endif
