#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return(document[n - 1][m - 1][k - 1]);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return(document[m - 1][k - 1]);
}

char*** kth_paragraph(char**** document, int k) {
    return(document[k - 1]);
}

char**** get_document(char* text) 
{
    int i = 0, cnt_prg = 0, cnt_snt = 0, cnt_wrd = 0, length = 0, g = 0, gl = 0, glc = 0;
    char    ****doc;
    int     cnt_sntcs[5];
    int     cnt_wrds[5][10];
    int     wrd_lng[5][10][50];
    while (text[i])
    {
        if (text[i] == '\n')
        {
            cnt_sntcs[cnt_prg] = cnt_snt;
            cnt_snt = 0;
            length = -1;
            cnt_prg++;
        }
        if (text[i] == '.')
        {
            wrd_lng[cnt_prg][cnt_snt][cnt_wrd] = length;
            cnt_wrd += 1;
            cnt_wrds[cnt_prg][cnt_snt] = cnt_wrd;
            cnt_wrd = 0;
            length = -1;
            cnt_snt++;
        }
        if (text[i] == ' ')
        {
            wrd_lng[cnt_prg][cnt_snt][cnt_wrd] = length;
            length = -1;
            cnt_wrd++;
        }
        length++;
        i++;
    }
    cnt_sntcs[cnt_prg] = cnt_snt;
    cnt_prg++;
    int glcn = 0;
    doc = (char ****)malloc(sizeof(char ***) * cnt_prg);
    g = 0;
    while(g < cnt_prg)
    {
        doc[g] = (char ***)malloc(sizeof(char **) * cnt_sntcs[g]);
        gl = 0;
        while (gl < cnt_sntcs[gl])
        {
            doc[g][gl] = (char **)malloc(sizeof(char *) * cnt_wrds[g][gl]);
            glc = 0;
            while (glc < cnt_wrds[g][gl])
            {
                doc[g][gl][glc] = (char *)malloc(sizeof(char) * wrd_lng[g][gl][glc] + 1);
                i = 0;
                while (text[glcn] && text[glcn] != '\n' && text[glcn] != ' ' && text[glcn] != '.')
                {
                    doc[g][gl][glc][i] = text[glcn];
                    i++;
                    glcn++;
                }
                doc[g][gl][glc][i] = '\0';
                while (text[glcn] == ' ' || text[glcn] == '\n' || text[glcn] == '.')
                    glcn++;
                glc++;
            }
            gl++;
        }
        g++;
    }
    return (doc);
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
