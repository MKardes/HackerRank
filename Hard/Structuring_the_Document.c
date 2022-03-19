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
struct document get_document(char* text) {
    int i = 0, prg_cnt = 0, snt_cnt = 0, word_cnt = 0, length = 0;
    struct document doc;
    struct paragraph *par;
    struct sentence *sent;
    struct word *word;
    printf("1.\n");
    doc.data = par;
    par.data[a] = sent;
    sent.data[s] = word;
    printf("12\n");
    while (text[i])
    {
	printf("1\n");
        if (text[i] == '\n')
        {
            doc.data[prg_cnt].sentence_count = snt_cnt;
            snt_cnt = 0;
            word_cnt = 0;
            length = -1;
            prg_cnt++;
        }
        if (text[i] == '.')
        {
            word_cnt++;
            doc.data[prg_cnt].data[snt_cnt].word_count = word_cnt;
            snt_cnt++;
            length = -1;
            word_cnt = 0;
        }
        if (text[i] == ' ')
        {
            word_cnt++;
            length = -1;
        }
        length++;
        i++;
    }
    prg_cnt++;
    doc.paragraph_count = prg_cnt;
    prg_cnt = 0;
    i = 0;
    while (prg_cnt < doc.paragraph_count)
    {
        doc.data = (struct paragraph *)malloc(sizeof(struct sentence *) * doc.paragraph_count);
        snt_cnt = 0;
        while (snt_cnt < doc.data[prg_cnt].sentence_count)
        {
            doc.data[prg_cnt].data = (struct sentence *)malloc(sizeof(struct word *) * doc.data[prg_cnt].sentence_count);
            word_cnt = 0;
            while(word_cnt < doc.data[prg_cnt].data[snt_cnt].word_count)
            {
                doc.data[prg_cnt].data[snt_cnt].data = (struct word *)malloc(sizeof(char *) * doc.data[prg_cnt].data[snt_cnt].word_count);
                length = 0;
                while (text[i] != '\n' && text[i] != ' ' && text[i] != '.' && text[i] != '\0')
                {
                    length++;
                    i++;
                }
                while (text[i] == '\n' && text[i] == ' ' && text[i] == '.')
                    i++;
                doc.data[prg_cnt].data[snt_cnt].data[word_cnt].data = (char *)malloc(sizeof(char) * length + 1);
                word_cnt++;
            }
            snt_cnt++;
        }
        prg_cnt++;
    }
    i = 0;
    prg_cnt = 0, snt_cnt = 0, word_cnt = 0, length = 0;
    while (text[i])
    {
        if (text[i] == '\n')
        {
            prg_cnt++;
            snt_cnt = 0;
            word_cnt = 0;
            length = -1;
        }
        if (text[i] == '.')
        {
            snt_cnt++;
            word_cnt = 0;
            length = -1;
        }
        if (text[i] == ' ')
        {
            word_cnt++;
            length = -1;
        }
        else
            doc.data[prg_cnt].data[snt_cnt].data[word_cnt].data[length] = text[i];
        length++;
        i++;
    }
    return(doc);
}
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    struct word wrd = Doc.data[n].data[m].data[k];
    return(wrd);
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    struct sentence snt = Doc.data[m].data[k];
    return(snt);
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    struct paragraph par = Doc.data[k];
    return par;
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
