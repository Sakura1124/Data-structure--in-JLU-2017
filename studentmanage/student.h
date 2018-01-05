#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <bits/stdc++.h>
#include<windows.h>

using namespace std;

int cmp_single_ctrl;///决定比较哪科成绩

///得分输入0可略去后面输出，单科成绩随机得到

///科目号从0到9

set<int> S;///学号集合

const int maxN = 1000002;
int next[maxN];

void color(const unsigned short color1)///修改字体颜色
{
    if(color1>=0&&color1<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
}
void getNext(char *str_mod)
{
    int tlen=strlen(str_mod);
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1;
    while(j < tlen)
        if(k == -1 || str_mod[j] == str_mod[k])
            next[++j] = ++k;
        else
            k = next[k];

}

int KMP_Count(char *str_main,char *str_mod)
{

    int tlen=strlen(str_mod);
    int slen=strlen(str_main);
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(str_main[0] == str_mod[0])
            return 1;
        else
            return 0;
    }
    getNext(str_mod);
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && str_main[i] != str_mod[j])
            j = next[j];
        if(str_main[i] == str_mod[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

struct stud
{
    char name[20];
    int number;
    int score_all;
    int score_detail[15];
    bool operator<(const stud &b)
    {
        return number<b.number;
    }
};

bool cmpa(stud a,stud b)
{
    return a.number<b.number;
}

bool cmpd(stud a,stud b)
{
    return a.number>b.number;
}

vector<stud> lis;
vector<stud>::iterator it,it2,it3;


void in(stud &a)
{
    int scoreall=0;
    int choice;
    cout<<" 请依次输入学生姓名,编号,总得分,单科得分："<<endl;
    scanf("%s %d %d",a.name,&a.number,&a.score_all);
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(it->number==a.number)
        {
            printf("该编号已存在,请重新输入！\n");
            return;
        }
    }
    if(a.score_all==0)
    {
        for(int i=0; i<10; i++)
        {
            a.score_detail[i]=rand()%51+50;
            a.score_all+=a.score_detail[i];
        }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            cin>>a.score_detail[i];
            scoreall+=a.score_detail[i];
        }
        if(scoreall!=a.score_all)
        {
            cout<<"总分有误，是否修改?(输入1修改)"<<endl;
            cin>>choice;
            if(choice==1)
                a.score_all=scoreall;
        }
    }
    lis.push_back(a);
    cout<<"\t\t[录入成功！……]"<<endl;
}

void push()
{
    stud a;
    in(a);
}///交互式输入
void datadownload()
{

    freopen("out.txt","r",stdin);
    stud a;
    while(~scanf("%s",a.name))
    {
        scanf("%d %d",&a.number,&a.score_all);
        if(a.score_all==0)
        {
            for(int i=0; i<10; i++)
            {
                a.score_detail[i]=rand()%51+50;
                a.score_all+=a.score_detail[i];
            }
        }
        else
        {
            for(int i=0; i<10; i++)
            {
                cin>>a.score_detail[i];
            }
        }
        lis.push_back(a);
    }

    fflush(stdin);


    freopen("CON","r",stdin);
}///一次性导入整个文件
void file_push()
{
    char f[50];

    cout<<" 请输入文件名："<<endl;
    cin>>f;
    freopen(f,"r",stdin);
    stud a;
    while(~scanf("%s",a.name))
    {
        scanf("%d %d",&a.number,&a.score_all);
        if(a.score_all==0)
        {
            for(int i=0; i<10; i++)
            {
                a.score_detail[i]=rand()%51+50;
                a.score_all+=a.score_detail[i];
            }
        }
        else
        {
            for(int i=0; i<10; i++)
            {
                cin>>a.score_detail[i];
            }
        }
        lis.push_back(a);
    }

    fflush(stdin);


    freopen("CON","r",stdin);
}///一次性导入整个文件


void out()
{
    cout<<" 所有学生信息如下:"<<endl;
    cout<<"姓名"<<"\t\t"<<"教学号"<<"\t\t"<<"总分"<<"\t"<<"英语"<<"\t"<<"线代"<<"\t"<<"高数"<<"\t"<<"java"<<"\t"<<"毛概"<<"\t"<<"马哲"<<"\t"<<"概率"<<"\t"<<"C++"<<"\t"<<"程设"<<"\t"<<"语文"<<"\t"<<endl;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        cout<<it->name<<"\t\t"<<it->number<<"\t"<<it->score_all<<"\t";
        for(int i=0; i<10; i++)
        {
            if(it->score_detail[i]<60)
            {
                color(12);
                cout<<it->score_detail[i]<<"\t";
                color(7);
            }
            else
                cout<<it->score_detail[i]<<"\t";
        }
        cout<<endl;
    }
}

void file_out()///文件输出
{

//    freopen("out.txt","a",stdout);
//    out();
//    freopen("CON","w",stdout);
//    fflush(stdin);
//    fflush(stdout);
    FILE *fp=fopen("out.txt","a");
    //  fprintf(fp,"所有学生信息如下：\n");
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        fprintf(fp,"%s\t\t%d\t%d\t",it->name,it->number,it->score_all);
        //  cout<<it->name<<" "<<it->number<<" "<<it->score_all<<" ";
        for(int i=0; i<10; i++)
        {
            fprintf(fp,"%d\t",it->score_detail[i]);
            //cout<<it->score_detail[i]<<" ";
        }
        //cout<<endl;
        putc('\n',fp);
    }
    fclose(fp);
}

void descend_order()
{
    cout<<" 输入0表示文件输出，其他表示屏幕输出："<<endl;
    int mod;
    scanf("%d",&mod);
    sort(lis.begin(),lis.end(),cmpd);
    if(mod)
    {
        out();
    }
    else
    {
        freopen("out.txt","a",stdout);
        out();
        freopen("CON","w",stdout);
    }
}

void ascend_order()
{
    cout<<" 输入0表示文件输出，其他表示屏幕输出："<<endl;
    int mod;
    scanf("%d",&mod);
    sort(lis.begin(),lis.end(),cmpa);
    if(mod)
    {
        out();
    }
    else
    {
        freopen("out.txt","a",stdout);
        out();
        freopen("CON","w",stdout);
    }
}

void file_renew()///文件更新
{
//    FILE *fp=freopen("out.txt","w",stdout);
//    out();
//    freopen("CON","w",stdout);
    FILE *fp=fopen("out.txt","w");
    //  fprintf(fp,"所有学生信息如下：\n");
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        fprintf(fp,"%s\t\t%d\t%d\t",it->name,it->number,it->score_all);
        //  cout<<it->name<<" "<<it->number<<" "<<it->score_all<<" ";
        for(int i=0; i<10; i++)
        {
            fprintf(fp,"%d\t",it->score_detail[i]);
            //cout<<it->score_detail[i]<<" ";
        }
        //cout<<endl;
        putc('\n',fp);
    }
    fclose(fp);
}

void ins()///切记插入之后自动变为按学号保持原序！
{
    stud a;
    in(a);
    if(lis.size()>=3)
    {
        it=lis.begin();
        it2=it;
        it2++;
        if(*it<*it2)
        {
            sort(lis.begin(),lis.end(),cmpa);
        }
        else
        {
            sort(lis.begin(),lis.end(),cmpd);
        }
    }
    file_renew();
}

void del()
{
    int a;
    cout<<" 请输入学生编号："<<endl;
    cin>>a;
    bool flag=0;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(it->number==a)
        {
            lis.erase(it);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("该编号不存在，删除失败！\n");
        return;
    }
    cout<<"\t\t[删除成功……]\n";
    file_renew();
}

void modify()
{
    int a;
    cout<<" 请输入学生编号："<<endl;
    cin>>a;

    bool flag=0;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(it->number==a)
        {
            flag=1;
            cout<<"该学生信息如下："<<endl;
            cout<<"姓名"<<"\t\t"<<"教学号"<<"\t\t"<<"总分"<<"\t"<<"英语"<<"\t"<<"线代"<<"\t"<<"高数"<<"\t"<<"java"<<"\t"<<"毛概"<<"\t"<<"马哲"<<"\t"<<"概率"<<"\t"<<"C++"<<"\t"<<"程设"<<"\t"<<"语文"<<"\t"<<endl;
            cout<<it->name<<"\t\t"<<it->number<<"\t"<<it->score_all<<"\t";
            for(int i=0; i<10; i++)
            {
                if(it->score_detail[i]<60)
                {
                    color(12);
                    cout<<it->score_detail[i]<<"\t";
                    color(7);
                }
                else
                    cout<<it->score_detail[i]<<"\t";

            }
            cout<<endl;
            break;
        }
    }
    if(flag==0)
    {
        printf("该编号不存在，修改失败！\n");
        return;
    }

    cout<<" 输入1表示修改单科成绩，2表示修改全部信息:"<<endl;
    int mod;
    cin>>mod;
    if(mod==2)
    {
        for(it=lis.begin(); it!=lis.end(); it++)
        {
            if(it->number==a)
            {
                stud b;
                cout<<" 请依次输入学生姓名,编号,得分："<<endl;
                scanf("%s %d %d",b.name,&b.number,&b.score_all);
                if(b.score_all==0)
                {
                    for(int i=0; i<10; i++)
                    {
                        b.score_detail[i]=rand()%51+50;
                        b.score_all+=b.score_detail[i];
                    }
                }
                else
                {
                    for(int i=0; i<10; i++)
                    {
                        cin>>b.score_detail[i];
                    }
                }
                *it=b;
            }
        }
        file_renew();
    }
    else
    {
        for(it=lis.begin(); it!=lis.end(); it++)
        {
            if(it->number==a)
            {
                cout<<" 您需要修改第几科成绩?"<<endl;
                int gn;
                scanf("%d",&gn);
                cout<<" 请输入新的成绩："<<endl;
                int newscore;
                cin>>newscore;
                it->score_detail[gn]=newscore;
                it->score_all=0;
                for(int i=0; i<10; i++)
                {
                    it->score_all+=it->score_detail[i];
                }
            }
        }
        file_renew();

    }
    cout<<"\t\t[修改成功]!"<<endl;
}



bool cmp_singlea(const stud &a,const stud &b)
{
    return a.score_detail[cmp_single_ctrl]<b.score_detail[cmp_single_ctrl];
}
bool cmp_singled(const stud &a,const stud &b)
{
    return a.score_detail[cmp_single_ctrl]>b.score_detail[cmp_single_ctrl];
}
bool cmp_alla(const stud &a,const stud &b)
{
    return a.score_all<b.score_all;
}
bool cmp_alld(const stud &a,const stud &b)
{
    return a.score_all>b.score_all;
}
void single_score_ascend()
{
    cout<<" 请输入要比较哪科成绩："<<endl;
    cin>>cmp_single_ctrl;
    sort(lis.begin(),lis.end(),cmp_singlea);
    out();
}

void single_score_descend()
{
    cout<<" 请输入要比较哪科成绩："<<endl;
    cin>>cmp_single_ctrl;
    sort(lis.begin(),lis.end(),cmp_singled);
    out();
}

void all_score_ascend()
{
    sort(lis.begin(),lis.end(),cmp_alla);
    out();
}

void all_score_descend()
{
    sort(lis.begin(),lis.end(),cmp_alld);
    out();
}

void stud_count()
{
    cout<<"姓名"<<"\t\t"<<"教学号"<<"\t\t"<<"总分"<<"\t"<<"均分"<<endl;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        cout<<it->name<<"\t\t"<<it->number<<"\t"<<it->score_all<<"\t"<<it->score_all/10.0<<endl;
    }
}

void subject_count()
{
    cout<<" 请输入要统计哪科成绩："<<endl;
    int k;
    cin>>k;
    int maxf=-1,minf=0x3f3f3f3f,sum=0,cnt=0;

    for(it=lis.begin(); it!=lis.end(); it++)
    {
        maxf=max(maxf,it->score_detail[k]);
        minf=min(minf,it->score_detail[k]);
        sum+=it->score_detail[k];
        cnt++;
    }
    cout<<" 最高分: "<<maxf<<endl;
    cout<<" 最低分: "<<minf<<endl;
    cout<<" 平均分: "<<sum*1.0/cnt<<endl;
}

void query_name_vague()
{
    cout<<" 请输入学生姓名关键字："<<endl;
    char str_mod[50];
    cin>>str_mod;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(KMP_Count(it->name,str_mod)>=1)
        {
            cout<<it->name<<"\t"<<it->number<<" "<<it->score_all<<" ";
               for(int i=0; i<10; i++)
        {
            if(it->score_detail[i]<60)
            {
                color(12);
                cout<<it->score_detail[i]<<" ";
                color(7);
            }
            else
                cout<<it->score_detail[i]<<" ";
        }
            cout<<endl;
        }
    }
}

void query_name_accurate()
{
    cout<<" 请输入完整学生姓名："<<endl;
    char str_mod[50];
    cin>>str_mod;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(strcmp(it->name,str_mod)==0)
        {
            cout<<it->name<<" "<<it->number<<" "<<it->score_all<<" ";
             for(int i=0; i<10; i++)
        {
            if(it->score_detail[i]<60)
            {
                color(12);
                cout<<it->score_detail[i]<<" ";
                color(7);
            }
            else
                cout<<it->score_detail[i]<<" ";
        }
            cout<<endl;
        }
    }
}

void query_number()
{
    cout<<" 请输入完整学生编号："<<endl;
    int str_mod;
    cin>>str_mod;
    bool flag=0;
    for(it=lis.begin(); it!=lis.end(); it++)
    {
        if(it->number==str_mod)
        {
            cout<<it->name<<" "<<it->number<<" "<<it->score_all<<" ";
             for(int i=0; i<10; i++)
        {
            if(it->score_detail[i]<60)
            {
                color(12);
                cout<<it->score_detail[i]<<" ";
                color(7);
            }
            else
                cout<<it->score_detail[i]<<" ";
        }
            cout<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("该编号不存在，查询失败！\n");
        return;
    }
}

void solve()
{

//    file_out();
//    cout<<"1"<<endl;
//    int a;
//    freopen("out.txt","r",stdin);
//    freopen("CON","r",stdin);
//    scanf("%d",&a);
//    ins();

}


#endif // STUDENT_H_INCLUDED
