# include<stdio.h>
# include<cs50.h>
# include<string.h>

typedef struct // type defintion struct 成對的交互對照
{
    string name;
    string number;
}
person; // 在大括號外命名該structure

int main(void)
{
  //int xxx[i]
    person people[2]; // 將people套用到名為person的sturcture, 並設資料長度為2
    people[0].name = "Bob";
    people[0].number = "123-456-789";
    people[1].name = "Ginger";
    people[1].number = "000-000-000";

    // people[1] = people[0];
    // printf("%s %s \n", people[1].name, people[1].number);
    string s = get_string("Serch name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(s, people[i].name) == 0)
        {
            printf("Found %s at %d\n", s, i);
            printf("Phone number: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
