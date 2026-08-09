#include <stdio.h>

int log2_approx(int n) {
    int count = 0;
    while (n > 1) {
        n /= 2;
        count++;
    }
    return count;
}

int main() {

    FILE *fp = fopen("dictionary_analysis.csv", "w");

    if (fp == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    fprintf(fp,
    "n,"
    "UA_Search,UA_Insert,UA_Delete,UA_Min,UA_Max,UA_Pred,UA_Succ,"
    "SA_Search,SA_Insert,SA_Delete,SA_Min,SA_Max,SA_Pred,SA_Succ,"
    "SLLU_Search,SLLU_Insert,SLLU_Delete,SLLU_Min,SLLU_Max,SLLU_Pred,SLLU_Succ,"
    "SLLS_Search,SLLS_Insert,SLLS_Delete,SLLS_Min,SLLS_Max,SLLS_Pred,SLLS_Succ,"
    "DLLU_Search,DLLU_Insert,DLLU_Delete,DLLU_Min,DLLU_Max,DLLU_Pred,DLLU_Succ,"
    "DLLS_Search,DLLS_Insert,DLLS_Delete,DLLS_Min,DLLS_Max,DLLS_Pred,DLLS_Succ\n");

    for (int n = 100; n <= 5000; n += 100) {

        int logn = log2_approx(n);

        /* ================= UNSORTED ARRAY ================= */
        int ua_search = n;
        int ua_insert = 1;
        int ua_delete = n;
        int ua_min = n;
        int ua_max = n;
        int ua_pred = n;
        int ua_succ = n;

        /* ================= SORTED ARRAY ================= */
        int sa_search = logn;
        int sa_insert = n;
        int sa_delete = n;
        int sa_min = 1;
        int sa_max = 1;
        int sa_pred = 1;
        int sa_succ = 1;

        /* ================= SLL UNSORTED ================= */
        int sllu_search = n;
        int sllu_insert = 1;
        int sllu_delete = n;
        int sllu_min = n;
        int sllu_max = n;
        int sllu_pred = n;
        int sllu_succ = n;

        /* ================= SLL SORTED ================= */
        int slls_search = n;
        int slls_insert = n;
        int slls_delete = n;
        int slls_min = 1;
        int slls_max = n;
        int slls_pred = n;
        int slls_succ = n;

        /* ================= DLL UNSORTED ================= */
        int dllu_search = n;
        int dllu_insert = 1;
        int dllu_delete = n;
        int dllu_min = n;
        int dllu_max = n;
        int dllu_pred = n;
        int dllu_succ = n;

        /* ================= DLL SORTED ================= */
        int dlls_search = n;
        int dlls_insert = n;
        int dlls_delete = n;
        int dlls_min = 1;
        int dlls_max = n;
        int dlls_pred = n;
        int dlls_succ = n;

        fprintf(fp,
        "%d,"
        "%d,%d,%d,%d,%d,%d,%d,"
        "%d,%d,%d,%d,%d,%d,%d,"
        "%d,%d,%d,%d,%d,%d,%d,"
        "%d,%d,%d,%d,%d,%d,%d,"
        "%d,%d,%d,%d,%d,%d,%d,"
        "%d,%d,%d,%d,%d,%d,%d\n",

        n,

        ua_search, ua_insert, ua_delete, ua_min, ua_max, ua_pred, ua_succ,
        sa_search, sa_insert, sa_delete, sa_min, sa_max, sa_pred, sa_succ,
        sllu_search, sllu_insert, sllu_delete, sllu_min, sllu_max, sllu_pred, sllu_succ,
        slls_search, slls_insert, slls_delete, slls_min, slls_max, slls_pred, slls_succ,
        dllu_search, dllu_insert, dllu_delete, dllu_min, dllu_max, dllu_pred, dllu_succ,
        dlls_search, dlls_insert, dlls_delete, dlls_min, dlls_max, dlls_pred, dlls_succ
        );
    }

    fclose(fp);

    printf("dictionary_analysis.csv generated successfully.\n");

    return 0;
}