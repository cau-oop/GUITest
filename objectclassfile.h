#ifndef OBJECTCLASSFILE_H
#define OBJECTCLASSFILE_H

#endif // OBJECTCLASSFILE_H
#pragma once
// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#define _CRT_SECURE_NO_WARNINGS
#include <QDialog>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "Login.h"
using namespace std;


class User
{
private:

public:
    string password="ASd";
    string name;
    string gender;
    string birth;
    string phone;
    string spam;
    string country;
    string city;
    char pack[50] = "pack";
    char review[50] = "review";
    char guide[50] = "guide";
    char rank[50] = "rank";
    char packname[50];
    char idtxt[50] = "abc";
    char id[50] = "abc";
    void PackReview()
    {
        string a;
        char packname[50];
        cout << "패키지 번호를 입력해주세요" << endl;
        cin >> packname;
        strcat_s(packname, ".");
        strcat_s(packname, review);
        cout << "패키지의 리뷰를 입력해주세요" << endl;
        cin >> a;
        ofstream fs(packname, ios::app);
        if (fs.is_open()) {
        }
        else {
            cout << "파일을 찾을 수 없습니다!" << endl;
        }
        fs << "\n" << a << " - " << id;
        fs.close();
    }
    void ChangeInfo()
    {
        int a;
        cout << "수정하고자 하는 요소를 선택해주세요" << endl;
        cin >> a;
        switch (a) {
        case 1:
            cout << "비밀번호 변경" << endl;
            cout << "변경내용 :" << endl;
            cin >> password;
            break;
        case 2:
            cout << "전화번호 변경" << endl;
            cout << "변경내용 :" << endl;
            cin >> phone;
            break;
        case 3:
            cout << "스팸여부 변경(동의하면 1, 아니면 0)" << endl;
            cout << "변경내용 :" << endl;
            cin >> spam;
            break;
        case 4:
            cout << "관심나라 변경" << endl;
            cout << "변경내용 :" << endl;
            cin >> country;
            break;
        case 5:
            cout << "관심도시 변경" << endl;
            cout << "변경내용 :" << endl;
            cin >> city;
            break;
        }
        ofstream fs4(idtxt, ios::ate);
        fs4 << password;
        fs4 << "\n" << name;
        fs4 << "\n" << gender;
        fs4 << "\n" << birth;
        fs4 << "\n" << phone;
        fs4 << "\n" << spam;
        fs4 << "\n" << city;
        fs4 << "\n" << country;
        fs4.close();
    }

};

class Licensee
{
private:
    string password;
    string name;
    string agency;
    string phone;
    string license;
    string city;
    string country;
public:
    void GetInfo()
    {
        string s;
        char id[50] = "abc";
        strcat_s(id, ".txt");
        fstream fs(id);
        getline(fs, password);
        getline(fs, name);
        getline(fs, agency);
        getline(fs, phone);
        getline(fs, license);
        getline(fs, city);
        getline(fs, country);
    }

};
class Guide
{
private:
    string password;
    string name;
    string phone;
    string license;
    string city;
    string country;
    string online;
public:
    void GetInfo()
    {
        string s;
        char id[50] = "";
        strcat_s(id, ".txt");
        fstream fs(id);
        getline(fs, password);
        getline(fs, name);
        getline(fs, phone);
        getline(fs, license);
        getline(fs, city);
        getline(fs, country);
        getline(fs, online);
    }

};
