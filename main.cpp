#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
struct student {
    string fio;
    double mat,fiz,prg,atsd,yfm, eng,bzd,tjms,dop;   //перелік усіх предметів та додаткових балів
    float sb,sr;
};
int size;

void inputFile(student *vid, float & sm,float& sf,float& sp,float& sa,float& sy,float& se, float& sbz, float& st ) {
    string path = "input.txt";
    ifstream file(path);
    //file.open(path,ifstream::in);
    int lines = 0;
    string str;
    while(getline(file,str))
    {
        lines ++;
    }
    size=lines/2;
    file.close();

    fstream fin;
    fin.open(path, fstream::in);
    if (!fin.is_open()) { cout << "Помилка відкриття файлу" << endl; }
    else {
        for (int i = 0; i < size; i++) {
            getline(fin, vid[i].fio);
            (fin >> vid[i].mat).get();
            fin >> vid[i].fiz;
            fin >> vid[i].prg;
            fin >> vid[i].atsd;
            fin >> vid[i].yfm;
            fin >> vid[i].eng;
            fin >> vid[i].bzd;
            fin >> vid[i].tjms;
            (fin >> vid[i].dop).get();

            //підрахунок середього балла з усіх предметів
            sm += vid[i].mat;
            sf += vid[i].fiz;
            sp += vid[i].prg;
            sa += vid[i].atsd;
            sy += vid[i].yfm;
            se += vid[i].eng;
            sbz += vid[i].bzd;
            st += vid[i].tjms;

            //підрахунок середньго та рейтингово балла кожного студента
            vid[i].sb =
                    (float(vid[i].mat + vid[i].fiz + vid[i].prg + vid[i].atsd + vid[i].yfm + vid[i].eng + vid[i].bzd +
                           vid[i].tjms)) / 8;
            vid[i].sr = (float(
                    ((((vid[i].mat) * 6 + (vid[i].fiz) * 3 + (vid[i].prg) * 3 + (vid[i].atsd) * 6 + (vid[i].yfm) * 4 +
                       (vid[i].eng) * 2 + (vid[i].bzd) * 3 + (vid[i].tjms) * 4) / 31) * 0.9) + (vid[i].dop) * 0.25));
        }
    }
}

void input(student *vid, float & sm,float& sf,float& sp,float& sa,float& sy,float& se, float& sbz, float& st ){
    cout<<"Введіть кількість студентів - ";
    (cin >> size).get();
    for(int i=0;i<size;i++){
        cout<<"####Заповніть декларацію для "<<i+1<<" студента\n ";
        {
            cout<<"Введіть ФІО студента: ";
            getline(cin, vid[i].fio);
            cout<<"Введіть оцінки: \n";
            cout<<"Вища матекатика - ";(cin>>vid[i].mat).get();
            cout<<"Фізика - ";cin>>vid[i].fiz;
            cout<<"Програмування - ";cin>>vid[i].prg;
            cout<<"АтСд - ";cin>>vid[i].atsd;
            cout<<"УФМ - ";cin>>vid[i].yfm;
            cout<<"Англійська - ";cin>>vid[i].eng;
            cout<<"Безпека життєдіяльності - ";cin>>vid[i].bzd;
            cout<<"ТЙМс - ";cin>>vid[i].tjms;
            cout<<"Додаткові балли(від 0 до 40) - ";(cin>>vid[i].dop).get();

            //підрахунок середього балла з усіх предметів
            sm+=vid[i].mat;
            sf+=vid[i].fiz;
            sp+=vid[i].prg;
            sa+=vid[i].atsd;
            sy+=vid[i].yfm;
            se+=vid[i].eng;
            sbz+=vid[i].bzd;
            st+=vid[i].tjms;

            //підрахунок середньго та рейтингово балла кожного студента
            vid[i].sb = (float(vid[i].mat+vid[i].fiz+vid[i].prg+vid[i].atsd+vid[i].yfm+vid[i].eng+vid[i].bzd+vid[i].tjms))/8;
            vid[i].sr = (float(((((vid[i].mat)*6+(vid[i].fiz)*3+(vid[i].prg)*3+(vid[i].atsd)*6+(vid[i].yfm)*4+(vid[i].eng)*2+(vid[i].bzd)*3+(vid[i].tjms)*4)/31)*0.9)+(vid[i].dop)*0.25));
        }
    }
    int p;
    string path = "input.txt";
    cout<<"Бажаєте зберегти введені данні в файлі 'input.txt'\n1.Так, дописати файл\n2.Так, перезаписати файл\n3.Ні\nЗробіть свій вибір - ";
    cin>>p;
    switch(p){
        case 1:{fstream fin(path, fstream::app);
            for (int i = 0; i < size; i++) {
                fin << vid[i].fio<<endl;
                fin << vid[i].mat<<" ";
                fin << vid[i].fiz<<" ";
                fin << vid[i].prg<<" ";
                fin << vid[i].atsd<<" ";
                fin << vid[i].yfm<<" ";
                fin << vid[i].eng<<" ";
                fin << vid[i].bzd<<" ";
                fin << vid[i].tjms<<" ";
                fin << vid[i].dop<<endl;
            }
            inputFile(vid,sm,sf,sp,sa,sy,se,sbz,st);
            fin.close();
        }
            break;
        case 2:{fstream fin(path, fstream::in);
            for (int i = 0; i < size; i++) {
                fin << vid[i].fio<<endl;
                fin << vid[i].mat<<" ";
                fin << vid[i].fiz<<" ";
                fin << vid[i].prg<<" ";
                fin << vid[i].atsd<<" ";
                fin << vid[i].yfm<<" ";
                fin << vid[i].eng<<" ";
                fin << vid[i].bzd<<" ";
                fin << vid[i].tjms<<" ";
                fin << vid[i].dop<<" "<<endl;
            }
            fin.close();
        }
            break;
        case 3:
            break;
    }
}

void vidomost(student *vid){
    int v;
    cout<<"\n###Відомість групи\n";
    cout.precision(4);
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio << endl << "ВМ - " << vid[i].mat <<"; Фізика - " << vid[i].fiz
             << "; Програмування - " << vid[i].prg << "; АТСД - " << vid[i].atsd<< "; УФМ - " << vid[i].yfm<<
             "; Англійська - " << vid[i].eng<< "; БЖД - " << vid[i].bzd<< "; ТЙМс - " << vid[i].tjms<<"; Серденій балл - "<<vid[i].sb << endl;
    }

    cout<<"Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    cin>>v;
    string path="Otchet.txt";
    ofstream fin;
    fin.open(path, ofstream::app);
    if(v==1){
        if(!fin.is_open()){cout<<"Помилка відкриття файлу"<<endl;}
        else{
            fin<<"\n###Відомість групи\n";
            for(int i=0;i<size;i++) {
                fin << i + 1 << ". " << vid[i].fio << endl << "ВМ - " << vid[i].mat <<"; Фізика - " << vid[i].fiz
                       << "; Програмування - " << vid[i].prg << "; АТСД - " << vid[i].atsd<< "; УФМ - " << vid[i].yfm<<
                       "; Англійська - " << vid[i].eng<< "; БЖД - " << vid[i].bzd<< "; ТЙМс - " << vid[i].tjms<<"; Серденій балл - "<<vid[i].sb << endl;}
        }
        fin.close();}

}

void rating(student *vid){
    sort(vid, vid+size, [](student &a, student &b) { return a.sr > b.sr;});
    int v;
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
    }
    string path="Otchet.txt";
    ofstream fout;
    fout.open(path, ofstream::app);
    cout<<"Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    cin>>v;
    if(v==1){
        if(!fout.is_open()){cout<<"Помилка відкриття файлу"<<endl;}
        else{
            fout<<"\nCписок студентів по рейтинговому балу\n";
            for(int i=0;i<size;i++) {
                fout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;}
        }
        fout.close();}
}

void alphabet(student *vid){
    sort(vid, vid+size, [](student &a, student &b) { return a.fio < b.fio;});
    int v;
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
    }
    string path="Otchet.txt";
    ofstream fout;
    fout.open(path, ofstream::app);
    cout<<"Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    cin>>v;
    if(v==1){
        if(!fout.is_open()){cout<<"Помилка відкриття файлу"<<endl;}
        else{
            fout<<"\nCписок студентів в алфавітному порядку\n";
            for(int i=0;i<size;i++) {
                fout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;}
        }
        fout.close();}
}

void medium(student *vid,float & sm,float& sf,float& sp,float& sa,float& sy,float& se, float& sbz, float& st){
    stringstream ss;
    int v;
    string path="Otchet.txt";
    ofstream fout;
    fout.open(path, ofstream::app);
    ss.str("");
    ss<<"\nСередній бал групи по предметам:"<<endl<<"Вища математика - "<<double(sm)/double(size)
    <<endl<<"Фізика - "<<double(sf)/double(size)<<endl
    <<"Програмування - "<<double(sp)/double(size)<<endl
    <<"АтСД - "<<double(sa)/double(size)<<endl
    <<"УФМ - "<<double(sy)/double(size)<<endl
    <<"Англійська - "<<double(se)/double(size)<<endl
    <<"БЖД - "<<double(sbz)/double(size)<<endl
    <<"ТЙМс - "<<double(st)/double(size)<<endl;
    cout << ss.str();

    cout<<"Бажаєте записати вивід у файл?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    cin>>v;
    if(v==1){
        if(!fout.is_open()){cout<<"Помилка відкриття файлу"<<endl;}
        else{
            fout<<ss.str();
        }
        fout.close();}
}

void excellent(student *vid){
    int v;
    string path="Otchet.txt";
    ofstream fout;
    fout.open(path, ofstream::app);

    vector<string> search;
    int p;
    cout<<"Оберіть предмет:\n1.Вища математика\n2.Фізика\n3.Програмування\n4.АтСД\n5.УФМ\n6.Англійська\n7.БЖД\n8.ТЙМс\n0.Повенутися до головного меню\nВиберіть потрібну опцію: ";
    cin>>p;
    if(p==1){
        cout<<"Відмінники з вищої математики\n";
        for(int i=0;i<size;i++){
            if(vid[i].mat>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==2){
        cout<<"Відмінники з Фізики\n";
        for(int i=0;i<size;i++){
            if(vid[i].fiz>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==3){
        cout<<"Відмінники з вищої математики\n";
        for(int i=0;i<size;i++){
            if(vid[i].prg>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==4){
        cout<<"Відмінники з АтСД\n";
        for(int i=0;i<size;i++){
            if(vid[i].atsd>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==5){
        cout<<"Відмінники з УФМ\n";
        for(int i=0;i<size;i++){
            if(vid[i].yfm>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==6){
        cout<<"Відмінники з Англійської\n";
        for(int i=0;i<size;i++){
            if(vid[i].eng>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==7){;
        cout<<"Відмінники з БЖД\n";
        for(int i=0;i<size;i++){
            if(vid[i].bzd>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає";
        }
    }
    if(p==8){
        cout<<"Відмінники з ТЙМс\n";
        for(int i=0;i<size;i++){
            if(vid[i].tjms>=96) {
                search.push_back(vid[i].fio);
            }
        }
        for(auto & i : search){
            cout<<i<<endl;
        }
        if(search.empty()){
            cout<<"Відмінників немає\n";
        }
    }

    cout<<"Бажаєте записати вивід у файл?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    cin>>v;
    if(v==1){
        if(!fout.is_open()){cout<<"Помилка відкриття файлу"<<endl;}
        else{
            switch (p) {
                case 1:fout<<"\nВідмінники з Вищої математики\n";break;
                case 2:fout<<"\nВідмінники з Фізики\n";break;
                case 3:fout<<"\nВідмінники з Программування\n";break;
                case 4:fout<<"\nВідмінники з АтСД\n";break;
                case 5:fout<<"\nВідмінники з УФМ\n";break;
                case 6:fout<<"\nВідмінники з Англійської\n";break;
                case 7:fout<<"\nВідмінники з БЖД\n";break;
                case 8:fout<<"\nВідмінники з ТЙМс\n";break;
            }
            for(int i=0;i<search.size();i++){
                fout<<search[i]<<endl;
            }
            if(search.empty()){
                fout<<"Відмінників немає\n";
            }
        }
        fout.close();}
}

void edit(student *vid, float & sm,float& sf,float& sp,float& sa,float& sy,float& se, float& sbz, float& st ){
    int v;
    string path = "input.txt";
    fstream fin;
    fin.open(path, ifstream::in);
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
    }
    cout<<"\nУвага!\nПри редактуванні данних студента буде зміненно файл input.txt, не забудьте заново перезаписати розрахунки для Otchet.txt!\nВведіть номер студента - ";
    (cin>>v).get();
    cout<<"####Заповніть декларацію для студента\n ";
    for (int i=v-1;i<size;i++){
        //підрахунок середього балла з усіх предметів
        sm-=vid[i].mat;
        sf-=vid[i].fiz;
        sp-=vid[i].prg;
        sa-=vid[i].atsd;
        sy-=vid[i].yfm;
        se-=vid[i].eng;
        sbz-=vid[i].bzd;
        st-=vid[i].tjms;

        cout<<"Введіть ФІО студента: ";
        getline(cin, vid[i].fio);
        cout<<"Введіть оцінки: \n";
        cout<<"Вища матекатика - ";(cin>>vid[i].mat).get();
        cout<<"Фізика - ";cin>>vid[i].fiz;
        cout<<"Програмування - ";cin>>vid[i].prg;
        cout<<"АтСд - ";cin>>vid[i].atsd;
        cout<<"УФМ - ";cin>>vid[i].yfm;
        cout<<"Англійська - ";cin>>vid[i].eng;
        cout<<"Безпека життєдіяльності - ";cin>>vid[i].bzd;
        cout<<"ТЙМс - ";cin>>vid[i].tjms;
        cout<<"Додаткові балли(від 0 до 40) - ";(cin>>vid[i].dop).get();

            //підрахунок середього балла з усіх предметів
            sm+=vid[i].mat;
            sf+=vid[i].fiz;
            sp+=vid[i].prg;
            sa+=vid[i].atsd;
            sy+=vid[i].yfm;
            se+=vid[i].eng;
            sbz+=vid[i].bzd;
            st+=vid[i].tjms;

            //підрахунок середньго та рейтингово балла кожного студента
            vid[i].sb = (float(vid[i].mat+vid[i].fiz+vid[i].prg+vid[i].atsd+vid[i].yfm+vid[i].eng+vid[i].bzd+vid[i].tjms))/8;
            vid[i].sr = (float(((((vid[i].mat)*6+(vid[i].fiz)*3+(vid[i].prg)*3+(vid[i].atsd)*6+(vid[i].yfm)*4+(vid[i].eng)*2+(vid[i].bzd)*3+(vid[i].tjms)*4)/31)*0.9)+(vid[i].dop)*0.25));
    }
    cout<<"\nТепер відомість виглядає так:\n";
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
        if (!fin.is_open()) { cout << "Помилка відкриття файлу" << endl; }
        else {
            for (int i = 0; i < size; i++) {
                fin << vid[i].fio<<endl;
                fin << vid[i].mat<<" ";
                fin << vid[i].fiz<<" ";
                fin << vid[i].prg<<" ";
                fin << vid[i].atsd<<" ";
                fin << vid[i].yfm<<" ";
                fin << vid[i].eng<<" ";
                fin << vid[i].bzd<<" ";
                fin << vid[i].tjms<<" ";
                fin << vid[i].dop<<endl;
            }

        }
    }
    fin.close();
}

void deleteS(student *vid){
    int v;
    string path = "input.txt";
    fstream fin;
    fin.open(path, fstream::out);
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
    }
    cout<<"\nУвага!\nПри видалені студента буде зміненно файл input.txt, не забудьте заново перезаписати розрахунки для Otchet.txt!\nВведіть номер студента - ";
    cin>>v;
    for (int i=v-1;i<size;i++){
        vid[i].fio=vid[i+1].fio;
        vid[i].mat=vid[i+1].mat;
        vid[i].fiz=vid[i+1].fiz;
        vid[i].prg=vid[i+1].prg;
        vid[i].atsd=vid[i+1].atsd;
        vid[i].yfm=vid[i+1].yfm;
        vid[i].eng=vid[i+1].eng;
        vid[i].bzd=vid[i+1].bzd;
        vid[i].tjms=vid[i+1].tjms;
        vid[i].sr=vid[i+1].sr;
        vid[i].sb=vid[i+1].sb;
        vid[i].dop=vid[i+1].dop;
    }
    --size;
    for(int i=0;i<size;i++) {
        cout << i + 1 << ". " << vid[i].fio<<"; Рейтинговий балл - "<<vid[i].sr << endl;
        if (!fin.is_open()) { cout << "Помилка відкриття файлу" << endl; }
        else {
            for (int i = 0; i < size; i++) {
                fin << vid[i].fio<<endl;
                fin << vid[i].mat<<" ";
                fin << vid[i].fiz<<" ";
                fin << vid[i].prg<<" ";
                fin << vid[i].atsd<<" ";
                fin << vid[i].yfm<<" ";
                fin << vid[i].eng<<" ";
                fin << vid[i].bzd<<" ";
                fin << vid[i].tjms<<" ";
                fin << vid[i].dop<<endl;
            }
            fin.close();
        }
    }
}


int main(){
    setlocale(LC_ALL,"Ukr");

    int k, p;
    float sm,sf,sp,sa,sy,se,sbz,st;//сер. бал по предметах
    sm=sf=sp=sa=sy=se=sbz=st=k=0;
    student *vid = new student[size];
    cout<<"Виберіть сбосіб вводу:\n1.Через файл 'input.txt'\n2.Заповнити відомість вручну\nЗробіть свій вибір - ";
    (cin>>p).get();
    if(p==1){
        inputFile(vid,sm,sf,sp,sa,sy,se,sbz,st);
    }
    else if(p==2){
        input(vid,sm,sf,sp,sa,sy,se,sbz,st);
    }
    vidomost(vid);

    while (k!=7){
        cout<<"###Головне меню\n1.Вивести список студентів по рейтинговому балу\n2.Вивести список студентів в алфавітному порядку\n3.Вивести середні бали групи з усіх предметів\n4.Пошук відміннків з\n5.Видалити студента\n6.Редагувати відомість студента\n7.Завершення роботи\nВиберіть потрібну опцію: ";
        cin>>k;
        switch (k) {
            case 1:
                rating(vid);
                break;
            case 2:
                alphabet(vid);
                break;
            case 3:
                medium(vid,sm,sf,sp,sa,sy,se,sbz,st);
                break;
            case 4:
                excellent(vid);
                break;
            case 5:
                deleteS(vid);break;
            case 6:
                edit(vid,sm,sf,sp,sa,sy,se,sbz,st);
                break;
        }
    }
    return 0;
}