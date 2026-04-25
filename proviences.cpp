void computeLPSArray(string pat, int M, int* lps) {
    int len = 0; // length of previous longest prefix suffix
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fallback
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}bool KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            return true; // pattern found
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1]; // jump using LPS
            } else {
                i++;
            }
        }
    }

    return false; // not found
}