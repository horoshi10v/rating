#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

struct student {
    std::string fio;
    double mat, fiz, prg, atsd, yfm, eng, bzd, tjms, dop;   //перелік усіх предметів та додаткових балів
    float sb, sr;
};
int size;

void reSaveF(student *vid){
    std::string path = "input.txt";
    std::fstream fin;
    fin.open(path, std::fstream::out);
    if (!fin.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
    else {
        for (int i = 0; i < size; i++) {
            fin << vid[i].fio << std::endl;
            fin << vid[i].mat << " ";
            fin << vid[i].fiz << " ";
            fin << vid[i].prg << " ";
            fin << vid[i].atsd << " ";
            fin << vid[i].yfm << " ";
            fin << vid[i].eng << " ";
            fin << vid[i].bzd << " ";
            fin << vid[i].tjms << " ";
            fin << vid[i].dop << std::endl;
        }
    }
    fin.close();
}

void inputFile(student* vid) {
    std::string path = "input.txt";
    std::fstream file(path);
    int lines = 0;
    std::string str;
    while (std::getline(file, str)){
        lines++;
    }
    size = lines / 2;
    file.close();

    std::fstream fin;
    fin.open(path, std::fstream::in);
    if (!fin.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
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

void input(student* vid) {
    std::cout << "Введіть кількість студентів - ";
    (std::cin >> size).get();
    for (int i = 0; i < size; i++) {
        std::cout << "####Заповніть декларацію для " << i + 1 << " студента\n ";
        {
            std::cout << "Введіть ФІО студента: ";
            getline(std::cin, vid[i].fio);
            std::cout << "Введіть оцінки: \n";
            std::cout << "Вища матекатика - "; (std::cin >> vid[i].mat).get();
            std::cout << "Фізика - "; std::cin >> vid[i].fiz;
            std::cout << "Програмування - "; std::cin >> vid[i].prg;
            std::cout << "АтСд - "; std::cin >> vid[i].atsd;
            std::cout << "УФМ - "; std::cin >> vid[i].yfm;
            std::cout << "Англійська - "; std::cin >> vid[i].eng;
            std::cout << "Безпека життєдіяльності - "; std::cin >> vid[i].bzd;
            std::cout << "ТЙМс - "; std::cin >> vid[i].tjms;
            std::cout << "Додаткові балли(від 0 до 40) - "; (std::cin >> vid[i].dop).get();

            //підрахунок середньго та рейтингово балла кожного студента
            vid[i].sb = (float(vid[i].mat + vid[i].fiz + vid[i].prg + vid[i].atsd + vid[i].yfm + vid[i].eng + vid[i].bzd + vid[i].tjms)) / 8;
            vid[i].sr = (float(((((vid[i].mat) * 6 + (vid[i].fiz) * 3 + (vid[i].prg) * 3 + (vid[i].atsd) * 6 + (vid[i].yfm) * 4 + (vid[i].eng) * 2 + (vid[i].bzd) * 3 + (vid[i].tjms) * 4) / 31) * 0.9) + (vid[i].dop) * 0.25));
        }
    }
    int p;
    std::string path = "input.txt";
    std::cout << "Бажаєте зберегти введені данні в файлі 'input.txt'\n1.Так, дописати файл\n2.Так, перезаписати файл\n3.Ні\nЗробіть свій вибір - ";
    std::cin >> p;
    switch (p) {
        case 1: {std::fstream fin(path, std::fstream::app);
            for (int i = 0; i < size; i++) {
                fin << vid[i].fio << std::endl;
                fin << vid[i].mat << " ";
                fin << vid[i].fiz << " ";
                fin << vid[i].prg << " ";
                fin << vid[i].atsd << " ";
                fin << vid[i].yfm << " ";
                fin << vid[i].eng << " ";
                fin << vid[i].bzd << " ";
                fin << vid[i].tjms << " ";
                fin << vid[i].dop << std::endl;
            }
            inputFile(vid);
        }
            break;
        case 2:
            reSaveF(vid);
            break;
        case 3:
            break;
    }
}

void vidomost(student* vid) {
    int v;
    std::cout << "\n###Відомість групи\n";
    std::cout.precision(4);
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << std::endl << "ВМ - " << vid[i].mat << "; Фізика - " << vid[i].fiz
                  << "; Програмування - " << vid[i].prg << "; АТСД - " << vid[i].atsd << "; УФМ - " << vid[i].yfm <<
                  "; Англійська - " << vid[i].eng << "; БЖД - " << vid[i].bzd << "; ТЙМс - " << vid[i].tjms << "; Серденій балл - " << vid[i].sb << std::endl;
    }

    std::cout << "Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    std::cin >> v;
    std::string path = "Otchet.txt";
    std::fstream fin;
    fin.open(path, std::fstream::app);
    if (v == 1) {
        if (!fin.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
        else {
            fin << "\n###Відомість групи\n";
            for (int i = 0; i < size; i++) {
                fin << i + 1 << ". " << vid[i].fio << std::endl << "ВМ - " << vid[i].mat << "; Фізика - " << vid[i].fiz
                    << "; Програмування - " << vid[i].prg << "; АТСД - " << vid[i].atsd << "; УФМ - " << vid[i].yfm <<
                    "; Англійська - " << vid[i].eng << "; БЖД - " << vid[i].bzd << "; ТЙМс - " << vid[i].tjms << "; Серденій балл - " << vid[i].sb << std::endl;
            }
        }
        fin.close();
    }

}

void rating(student* vid) {
    std::sort(vid, vid + size, [](student& a, student& b) { return a.sr > b.sr; });
    int v;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    std::string path = "Otchet.txt";
    std::fstream fout;
    fout.open(path, std::fstream::app);
    std::cout << "Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    std::cin >> v;
    if (v == 1) {
        if (!fout.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
        else {
            fout << "\nCписок студентів по рейтинговому балу\n";
            for (int i = 0; i < size; i++) {
                fout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
            }
        }
        fout.close();
    }
}

void alphabet(student* vid) {
    std::sort(vid, vid + size, [](student& a, student& b) { return a.fio < b.fio; });
    int v;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    std::string path = "Otchet.txt";
    std::fstream fout;
    fout.open(path, std::fstream::app);
    std::cout << "Бажаєте записати вивід у файл 'Otchet.txt'?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    std::cin >> v;
    if (v == 1) {
        if (!fout.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
        else {
            fout << "\nCписок студентів в алфавітному порядку\n";
            for (int i = 0; i < size; i++) {
                fout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
            }
        }
        fout.close();
    }
}

void medium(student* vid, float& sm, float& sf, float& sp, float& sa, float& sy, float& se, float& sbz, float& st) {
    std::stringstream ss;

    sm = sf = sp = sa = sy = se = sbz = st = 0;
    int v;
    std::string path = "Otchet.txt";
    std::fstream fout;
    fout.open(path, std::fstream::app);
    ss.str("");
    //підрахунок середього балла з усіх предметів
    for (int i=0;i<size;i++){
        sm += vid[i].mat;
        sf += vid[i].fiz;
        sp += vid[i].prg;
        sa += vid[i].atsd;
        sy += vid[i].yfm;
        se += vid[i].eng;
        sbz += vid[i].bzd;
        st += vid[i].tjms;
    }
    ss << "\nСередній бал групи по предметам:" << std::endl << "Вища математика - " << double(sm) / double(size)
       << std::endl << "Фізика - " << double(sf) / double(size) << std::endl
       << "Програмування - " << double(sp) / double(size) << std::endl
       << "АтСД - " << double(sa) / double(size) << std::endl
       << "УФМ - " << double(sy) / double(size) << std::endl
       << "Англійська - " << double(se) / double(size) << std::endl
       << "БЖД - " << double(sbz) / double(size) << std::endl
       << "ТЙМс - " << double(st) / double(size) << std::endl;
    std::cout << ss.str();

    std::cout << "Бажаєте записати вивід у файл?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    std::cin >> v;
    if (v == 1) {
        if (!fout.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
        else {
            fout << ss.str();
        }
        fout.close();
    }
}

void excellent(student* vid) {
    int v;
    std::string path = "Otchet.txt";
    std::fstream fout;
    fout.open(path, std::fstream::app);

    std::vector<std::string> search;
    int p;
    std::cout << "Оберіть предмет:\n1.Вища математика\n2.Фізика\n3.Програмування\n4.АтСД\n5.УФМ\n6.Англійська\n7.БЖД\n8.ТЙМс\n0.Повенутися до головного меню\nВиберіть потрібну опцію: ";
    std::cin >> p;
    if (p == 1) {
        std::cout << "Відмінники з вищої математики\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].mat >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 2) {
        std::cout << "Відмінники з Фізики\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].fiz >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 3) {
        std::cout << "Відмінники з програмування\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].prg >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 4) {
        std::cout << "Відмінники з АтСД\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].atsd >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 5) {
        std::cout << "Відмінники з УФМ\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].yfm >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 6) {
        std::cout << "Відмінники з Англійської\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].eng >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 7) {
        ;
        std::cout << "Відмінники з БЖД\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].bzd >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }
    if (p == 8) {
        std::cout << "Відмінники з ТЙМс\n";
        for (int i = 0; i < size; i++) {
            if (vid[i].tjms >= 96) {
                search.push_back(vid[i].fio);
            }
        }
        for (auto& i : search) {
            std::cout << i << std::endl;
        }
        if (search.empty()) {
            std::cout << "Відмінників немає\n";
        }
    }

    std::cout << "Бажаєте записати вивід у файл?\n1.Так\t2.Ні\nЗробіть свій вибір: ";
    std::cin >> v;
    if (v == 1) {
        if (!fout.is_open()) { std::cout << "Помилка відкриття файлу" << std::endl; }
        else {
            switch (p) {
                case 1:fout << "\nВідмінники з Вищої математики\n"; break;
                case 2:fout << "\nВідмінники з Фізики\n"; break;
                case 3:fout << "\nВідмінники з Программування\n"; break;
                case 4:fout << "\nВідмінники з АтСД\n"; break;
                case 5:fout << "\nВідмінники з УФМ\n"; break;
                case 6:fout << "\nВідмінники з Англійської\n"; break;
                case 7:fout << "\nВідмінники з БЖД\n"; break;
                case 8:fout << "\nВідмінники з ТЙМс\n"; break;
            }
            for (int i = 0; i < search.size(); i++) {
                fout << search[i] << std::endl;
            }
            if (search.empty()) {
                fout << "Відмінників немає\n";
            }
        }
        fout.close();
    }
}

void edit(student* vid, float& sm, float& sf, float& sp, float& sa, float& sy, float& se, float& sbz, float& st) {
    int i;
    std::string path = "input.txt";
    std::fstream fin;
    fin.open(path, std::fstream::out);
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    std::cout << "\nУвага!\nПри редактуванні данних студента буде зміненно файл input.txt, не забудьте заново перезаписати розрахунки для Otchet.txt!\nВведіть номер студента - ";
    (std::cin >> i).get();
    --i;
    std::cout << "####Заповніть декларацію для студента\n ";
        std::cout << "Введіть ФІО студента: ";
        getline(std::cin, vid[i].fio);
        std::cout << "Введіть оцінки: \n";
        std::cout << "Вища матекатика - "; (std::cin >> vid[i].mat).get();
        std::cout << "Фізика - "; std::cin >> vid[i].fiz;
        std::cout << "Програмування - "; std::cin >> vid[i].prg;
        std::cout << "АтСд - "; std::cin >> vid[i].atsd;
        std::cout << "УФМ - "; std::cin >> vid[i].yfm;
        std::cout << "Англійська - "; std::cin >> vid[i].eng;
        std::cout << "Безпека життєдіяльності - "; std::cin >> vid[i].bzd;
        std::cout << "ТЙМс - "; std::cin >> vid[i].tjms;
        std::cout << "Додаткові балли(від 0 до 40) - "; (std::cin >> vid[i].dop).get();

        //підрахунок середньго та рейтингово балла кожного студента
        vid[i].sb = (float(vid[i].mat + vid[i].fiz + vid[i].prg + vid[i].atsd + vid[i].yfm + vid[i].eng + vid[i].bzd + vid[i].tjms)) / 8;
        vid[i].sr = (float(((((vid[i].mat) * 6 + (vid[i].fiz) * 3 + (vid[i].prg) * 3 + (vid[i].atsd) * 6 + (vid[i].yfm) * 4 + (vid[i].eng) * 2 + (vid[i].bzd) * 3 + (vid[i].tjms) * 4) / 31) * 0.9) + (vid[i].dop) * 0.25));

    std::cout << "\nТепер відомість виглядає так:\n";
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    reSaveF(vid);
}

void deleteS(student* vid, float& sm, float& sf, float& sp, float& sa, float& sy, float& se, float& sbz, float& st) {
    int v;

    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    std::cout << "\nУвага!\nПри видалені студента буде зміненно файл input.txt, не забудьте заново перезаписати розрахунки для Otchet.txt!\nВведіть номер студента - ";
    std::cin >> v;
   for (int i = v - 1; i < size; i++) {

        vid[i].fio = vid[i + 1].fio;
        vid[i].mat = vid[i + 1].mat;
        vid[i].fiz = vid[i + 1].fiz;
        vid[i].prg = vid[i + 1].prg;
        vid[i].atsd = vid[i + 1].atsd;
        vid[i].yfm = vid[i + 1].yfm;
        vid[i].eng = vid[i + 1].eng;
        vid[i].bzd = vid[i + 1].bzd;
        vid[i].tjms = vid[i + 1].tjms;
        vid[i].sr = vid[i + 1].sr;
        vid[i].sb = vid[i + 1].sb;
        vid[i].dop = vid[i + 1].dop;
   }
    --size;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << vid[i].fio << "; Рейтинговий балл - " << vid[i].sr << std::endl;
    }
    reSaveF(vid);
}




int main() {
    setlocale(LC_ALL, "Ukr");
    float sm, sf, sp, sa, sy, se, sbz, st;//сер. бал по предметах
    int k, p;

    student* vid = new student[size];
    std::cout << "Виберіть сбосіб вводу:\n1.Через файл 'input.txt'\n2.Заповнити відомість вручну\nЗробіть свій вибір - ";
    (std::cin >> p).get();
    if (p == 1) {
        inputFile(vid);
    }
    else if (p == 2) {
        input(vid);
    }
    vidomost(vid);

    while (k != 8) {
        std::cout << "###Головне меню\n1.Вивести список студентів по рейтинговому балу\n2.Вивести список студентів в алфавітному порядку\n3.Вивести середні бали групи з усіх предметів\n4.Пошук відміннків з\n5.Видалити студента\n6.Редагувати відомість студента\n7.Додати нових студентів\n8.Завершення роботи\nВиберіть потрібну опцію: ";
        std::cin >> k;
        switch (k) {
            case 1:
                rating(vid);
                break;
            case 2:
                alphabet(vid);
                break;
            case 3:
                medium(vid, sm, sf, sp, sa, sy, se, sbz, st);
                break;
            case 4:
                excellent(vid);
                break;
            case 5:
                deleteS(vid, sm, sf, sp, sa, sy, se, sbz, st);
                break;
            case 6:
                edit(vid, sm, sf, sp, sa, sy, se, sbz, st);
                break;
            case 7:
                input(vid);
                break;
        }
    }

    return 0;
}