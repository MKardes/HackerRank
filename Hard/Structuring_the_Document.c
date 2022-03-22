#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text)
{
    int i = 0;
    /*
    int cnt_prg = 0, cnt_snt = 0, cnt_wrd = 0;
    int     cnt_sntcs[5];
    int     cnt_wrds[5][5];
    int     wrd_lng[5][5][1005];
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
    */
    struct document doc;
    doc.data = malloc(sizeof(struct paragraph) * 5);
    doc.paragraph_count = 0;
    int j, k;
    i = 0;
    while (i < 5)
    {
        doc.data[i].data = malloc(sizeof(struct sentence) * 16);
        doc.data[i].sentence_count = 0;
        j = 0;
        while (j < 16)
        {
            doc.data[i].data[j].data = malloc(sizeof(struct word) * 128);
            doc.data[i].data[j].word_count = 0;
            k = 0;
            while (k < 128)
            {
                doc.data[i].data[j].data[k].data = malloc(sizeof(char) * 256);
                k++;
            }
            j++;
        }
        i++;
    }
    int l = 0, glcn = 0; 
    i = 0, j = 0, k = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '\n')
        {
            doc.data[j].data[k].data[l].data[glcn] = '\0';
            doc.paragraph_count++;
            j++;
            k = 0;
            l = 0;
            glcn = 0;
        }
	else if (text[i] == '.')
        {
            doc.data[j].data[k].data[l].data[glcn] = '\0';
            doc.data[j].data[k].word_count++;
            doc.data[j].sentence_count++;
            l = 0;
            glcn = 0;
            k++;
        }
	else if (text[i] == ' ')
        {
            doc.data[j].data[k].data[l].data[glcn] = '\0';
            doc.data[j].data[k].word_count++;
            l++;
            glcn = 0;
        }
        else
        {
            doc.data[j].data[k].data[l].data[glcn] = text[i];
            glcn++;
        }
        i++;
    }
    return (doc);
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return(Doc.data[n - 1].data[m - 1].data[k - 1]);
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return(Doc.data[m - 1].data[k - 1]);
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return (Doc.data[k - 1]);
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
