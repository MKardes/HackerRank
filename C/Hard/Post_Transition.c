#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

package *package_fix(package *pack, int a, int package_cnt)
{
    int i = 0;
    while (i < package_cnt - 1)
    {
        pack[i] = pack[i + 1];
        i++;
    }
    return (pack);
}

void print_all_packages(town t)
{
    printf("%s:\n",t.name);
    int i = 0, j;
    while (i < t.offices_count)
    {
        printf("\t%d:\n",i);
        j = 0;
        while (j < t.offices[i].packages_count)
        {
            printf("\t\t%s\n",t.offices[i].packages[j].id);
            j++;
        }
        i++;
    }
}

int is_movalbe(post_office po, int w)
{
    if (w >= po.min_weight && w <= po.max_weight)
        return 1;
    return 0;
}

void send_all_acceptable_packages (town *s, int si, town *t, int ti)
{
    int i = 0, j;

    while(i < s->offices[si].packages_count)
    {
        if(is_movalbe(t->offices[ti], s->offices[si].packages[i].weight))
        {
            int *tp = &t->offices[ti].packages_count;
            t->offices[ti].packages = (package *)realloc (t->offices[ti].packages, (*tp+1) * sizeof(package));
            t->offices[ti].packages[(*tp)++] = s->offices[si].packages[i];
            int *sp = &s->offices[si].packages_count;
            for (j = i; j< *sp - 1; j++)
            {
                s->offices[si].packages[j] = s->offices[si].packages[j+1];
            }        
            s->offices[si].packages = (package *)realloc(s->offices[si].packages, (*sp-1) * sizeof(package));
            (*sp)--;
        }
        else i++;
    }
}

town town_with_most_packages(town* towns, int towns_count)
{
    int i = 0, j = 0, t = 0, total = -1, ret = 0;
    while (i < towns_count)
    {
        j = 0;
        t = 0;
        while (j < towns[i].offices_count)
        {
            t += towns[i].offices[j].packages_count;
            j++;
        }
        if (total < t)
        {
            total = t;
            ret = i;
        }
        i++;
    }
    return (towns[ret]);
}

town* find_town(town* towns, int towns_count, char* name)
{
    int i = 0, j = 0, a = 0;
    while (j < towns_count && name[i])
    {
        i = 0;
        a = 0;
        while (name[a] == towns[j].name[a])
        {
            if (name[a + 1] == '\0' && towns[j].name[a + 1] == '\0')
                return (&towns[j]);
            a++;
        }
        j++;
    }
    return(NULL);
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2:
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}

