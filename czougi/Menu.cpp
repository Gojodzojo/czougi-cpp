#include "Menu.h"

using namespace sf;
using namespace std;

string ster[101] = {
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
        "Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7",
        "8","9","ESC","LC","LS","LA","Lsys","RC","RS","RA","Rsys","menu","[",
        "]",";",",",".","'","/","\\","~","=","-","Sp","EN","BS","tab","PU",
        "PD","end","home","Ins","Del","+","-","*","/","LA","RA","UA","DA",
        "0","1","2","3","4","5","6","7","8","9","F1","F2","F3","F4","F5","F6",
        "F7","F8","F9","F10","F11","F12","F13","F14","F15","Pause"

};

Menu::Menu(int okno) : okno(okno)
{
    z2 = 1;

    //Wstep-----------------------------------
    Tlo1 = Sprite(*tlo);
    Tlo1.setPosition(0, 0);

    Tytol1 = Sprite(*Tytol);
    Tytol1.setPosition(395, 200);

    tekst.setFont(sansExtraBold);
    tekst.setString("Wcisnij lewy przycisk myszy aby kontynuowac!");
    tekst.setPosition(140, 700);
    tekst.setCharacterSize(40);
    tekst.setFillColor(Color::Red);

    tekst2.setFont(sansExtraBold);
    tekst2.setString("Wcisnij ESCAPE aby zakonczyc dzialanie programu...");
    tekst2.setPosition(320, 770);
    tekst2.setCharacterSize(20);
    tekst2.setFillColor(Color::Red);

    //Menu------------------------------------------------------------
    float x2 = 472.5, y2 = 320;

    convex.setPointCount(8);

    convex.setPoint(0, Vector2f(x2 + 20, y2));
    convex.setPoint(1, Vector2f(x2, y2 + 20));
    convex.setPoint(2, Vector2f(x2, y2 + 100));
    convex.setPoint(3, Vector2f(x2 + 20, y2 + 120));
    convex.setPoint(4, Vector2f(x2 + 285, y2 + 120));
    convex.setPoint(5, Vector2f(x2 + 305, y2 + 100));
    convex.setPoint(6, Vector2f(x2 + 305, y2 + 20));
    convex.setPoint(7, Vector2f(x2 + 285, y2));

    convex.setFillColor(Color(150, 50, 250));
    convex.setOutlineThickness(10);
    convex.setOutlineColor(Color(250, 150, 100));

    tekst3.setFont(sansExtraBold);
    tekst3.setString("Graj!");
    tekst3.setPosition(x2 + 25, y2 - 10);
    tekst3.setCharacterSize(100);
    tekst3.setFillColor(Color::Red);

    x2 = 497.5; y2 = 500;

    convex3.setPointCount(8);

    convex3.setPoint(0, Vector2f(x2 + 20, y2));
    convex3.setPoint(1, Vector2f(x2, y2 + 20));
    convex3.setPoint(2, Vector2f(x2, y2 + 80));
    convex3.setPoint(3, Vector2f(x2 + 20, y2 + 100));
    convex3.setPoint(4, Vector2f(x2 + 235, y2 + 100));
    convex3.setPoint(5, Vector2f(x2 + 255, y2 + 80));
    convex3.setPoint(6, Vector2f(x2 + 255, y2 + 20));
    convex3.setPoint(7, Vector2f(x2 + 235, y2));

    convex3.setFillColor(Color(150, 50, 250));
    convex3.setOutlineThickness(10);
    convex3.setOutlineColor(Color(250, 150, 100));

    tekst5.setFont(sansExtraBold);
    tekst5.setString("Opcje");
    tekst5.setPosition(x2 + 12, y2 - 5);
    tekst5.setCharacterSize(80);
    tekst5.setFillColor(Color::Red);


    x2 = 25; y2 = 800;

    convex4.setPointCount(8);

    convex4.setPoint(0, Vector2f(x2 + 20, y2));
    convex4.setPoint(1, Vector2f(x2, y2 + 20));
    convex4.setPoint(2, Vector2f(x2, y2 + 50));
    convex4.setPoint(3, Vector2f(x2 + 20, y2 + 70));
    convex4.setPoint(4, Vector2f(x2 + 165, y2 + 70));
    convex4.setPoint(5, Vector2f(x2 + 185, y2 + 50));
    convex4.setPoint(6, Vector2f(x2 + 185, y2 + 20));
    convex4.setPoint(7, Vector2f(x2 + 165, y2));

    convex4.setFillColor(Color(96, 96, 96));
    convex4.setOutlineThickness(8);
    convex4.setOutlineColor(Color(32, 32, 32));

    tekst6.setFont(sansExtraBold);
    tekst6.setString("Autorzy");
    tekst6.setPosition(x2 + 20, y2 + 10);
    tekst6.setCharacterSize(35);
    tekst6.setFillColor(Color::White);

    //--------------------------------------------Tworcy
    x2 = 167.5; y2 = 300;

    convex5.setPointCount(8);

    convex5.setPoint(0, Vector2f(x2 + 50, y2));
    convex5.setPoint(1, Vector2f(x2, y2 + 50));
    convex5.setPoint(2, Vector2f(x2, y2 + 400));
    convex5.setPoint(3, Vector2f(x2 + 50, y2 + 450));
    convex5.setPoint(4, Vector2f(x2 + 865, y2 + 450));
    convex5.setPoint(5, Vector2f(x2 + 915, y2 + 400));
    convex5.setPoint(6, Vector2f(x2 + 915, y2 + 50));
    convex5.setPoint(7, Vector2f(x2 + 865, y2));

    convex5.setFillColor(Color(255, 215, 0));
    convex5.setOutlineThickness(15);
    convex5.setOutlineColor(Color(255, 140, 0));

    tekst7.setFont(sansExtraBold);
    tekst7.setString("Gra stworzona dzieki wspolpracy");
    tekst7.setPosition(x2 + 25, y2 + 30);
    tekst7.setCharacterSize(50);
    tekst7.setFillColor(Color(60, 60, 60));

    tekst8.setFont(sansExtraBold);
    tekst8.setString("Artur Kostera");
    tekst8.setPosition(x2 + 35, y2 + 200);
    tekst8.setCharacterSize(50);
    tekst8.setFillColor(Color::Black);

    tekst9.setFont(sansExtraBold);
    tekst9.setString("Adam Kaszubowski");
    tekst9.setPosition(x2 + 210, y2 + 320);
    tekst9.setCharacterSize(50);
    tekst9.setFillColor(Color::Black);

    tekst10.setFont(sansExtraBold);
    tekst10.setString("Mateusz Goik");
    tekst10.setPosition(x2 + 500, y2 + 200);
    tekst10.setCharacterSize(50);
    tekst10.setFillColor(Color::Black);

    //----------------------------------------------------------------Ustawienia

    x2 = 120; y2 = 125;

    convex6.setPointCount(8);

    convex6.setPoint(0, Vector2f(x2 + 50, y2));
    convex6.setPoint(1, Vector2f(x2, y2 + 50));
    convex6.setPoint(2, Vector2f(x2, y2 + 600));
    convex6.setPoint(3, Vector2f(x2 + 50, y2 + 650));
    convex6.setPoint(4, Vector2f(x2 + 965, y2 + 650));
    convex6.setPoint(5, Vector2f(x2 + 1010, y2 + 600));
    convex6.setPoint(6, Vector2f(x2 + 1010, y2 + 50));
    convex6.setPoint(7, Vector2f(x2 + 965, y2));

    convex6.setFillColor(Color(69, 69, 69));
    convex6.setOutlineThickness(15);
    convex6.setOutlineColor(Color(233, 116, 81));


    //-------------------------------------------------Czerwony   1
    tekst11.setFont(sansExtraBold);
    tekst11.setString("Gracz 1");
    tekst11.setPosition(x2 + 90, y2 + 60);
    tekst11.setCharacterSize(60);
    tekst11.setFillColor(Color::Red);

    tekst12.setFont(sansExtraBold);
    tekst12.setString("Przod: ");
    tekst12.setCharacterSize(40);
    tekst12.setFillColor(Color::Red);
    tekst12.setPosition(x2 + 50, y2 + 150);

    rectangle1 = RectangleShape(Vector2f(75, 50));
    rectangle1.setFillColor(Color::White);
    rectangle1.setPosition(x2 + 190, y2 + 150);
    
    litera1.setFont(sansExtraBold);
    litera1.setString(ster[playersKeybindings[0].up]);
    litera1.setCharacterSize(40);
    litera1.setFillColor(Color::Black);
    litera1.setPosition(x2 + 200, y2 + 150);

    tekst13.setFont(sansExtraBold);
    tekst13.setString("Tyl: ");
    tekst13.setCharacterSize(40);
    tekst13.setFillColor(Color::Red);
    tekst13.setPosition(x2 + 290, y2 + 150);

    rectangle2 = RectangleShape(Vector2f(75, 50));
    rectangle2.setFillColor(Color::White);
    rectangle2.setPosition(x2 + 440, y2 + 150);
    
    litera2.setFont(sansExtraBold);
    litera2.setString(ster[playersKeybindings[0].down]);
    litera2.setCharacterSize(40);
    litera2.setFillColor(Color::Black);
    litera2.setPosition(x2 + 450, y2 + 150);

    tekst14.setFont(sansExtraBold);
    tekst14.setString("Lewo: ");
    tekst14.setCharacterSize(40);
    tekst14.setFillColor(Color::Red);
    tekst14.setPosition(x2 + 50, y2 + 220);

    rectangle3 = RectangleShape(Vector2f(75, 50));
    rectangle3.setFillColor(Color::White);
    rectangle3.setPosition(x2 + 190, y2 + 220);

    litera3.setFont(sansExtraBold);
    litera3.setString(ster[playersKeybindings[0].left]);
    litera3.setCharacterSize(40);
    litera3.setFillColor(Color::Black);
    litera3.setPosition(x2 + 200, y2 + 220);

    tekst15.setFont(sansExtraBold);
    tekst15.setString("Prawo: ");
    tekst15.setCharacterSize(40);
    tekst15.setFillColor(Color::Red);
    tekst15.setPosition(x2 + 290, y2 + 220);

    rectangle4 = RectangleShape(Vector2f(75, 50));
    rectangle4.setFillColor(Color::White);
    rectangle4.setPosition(x2 + 440, y2 + 220);

    litera4.setFont(sansExtraBold);
    litera4.setString(ster[playersKeybindings[0].right]);
    litera4.setCharacterSize(40);
    litera4.setFillColor(Color::Black);
    litera4.setPosition(x2 + 450, y2 + 220);

    tekst31.setFont(sansExtraBold);
    tekst31.setString("Strzal: ");
    tekst31.setCharacterSize(40);
    tekst31.setFillColor(Color::Red);
    tekst31.setPosition(x2 + 140, y2 + 290);

    rectangle17 = RectangleShape(Vector2f(75, 50));
    rectangle17.setFillColor(Color::White);
    rectangle17.setPosition(x2 + 290, y2 + 290);

    litera17.setFont(sansExtraBold);
    litera17.setString(ster[playersKeybindings[0].shot]);
    litera17.setCharacterSize(40);
    litera17.setFillColor(Color::Black);
    litera17.setPosition(x2 + 300, y2 + 290);

    //-------------------------------------------Zolty   2
    tekst16.setFont(sansExtraBold);
    tekst16.setString("Gracz 2");
    tekst16.setPosition(x2 + 90, y2 + 350);
    tekst16.setCharacterSize(60);
    tekst16.setFillColor(Color::Yellow);

    tekst17.setFont(sansExtraBold);
    tekst17.setString("Przod: ");
    tekst17.setCharacterSize(40);
    tekst17.setFillColor(Color::Yellow);
    tekst17.setPosition(x2 + 50, y2 + 440);

    rectangle5 = RectangleShape(Vector2f(75, 50));
    rectangle5.setFillColor(Color::White);
    rectangle5.setPosition(x2 + 190, y2 + 440);

    litera5.setFont(sansExtraBold);
    litera5.setString(ster[playersKeybindings[1].up]);
    litera5.setCharacterSize(40);
    litera5.setFillColor(Color::Black);
    litera5.setPosition(x2 + 200, y2 + 440);

    tekst18.setFont(sansExtraBold);
    tekst18.setString("Tyl: ");
    tekst18.setCharacterSize(40);
    tekst18.setFillColor(Color::Yellow);
    tekst18.setPosition(x2 + 290, y2 + 440);

    rectangle6 = RectangleShape(Vector2f(75, 50));
    rectangle6.setFillColor(Color::White);
    rectangle6.setPosition(x2 + 440, y2 + 440);

    litera6.setFont(sansExtraBold);
    litera6.setString(ster[playersKeybindings[1].down]);
    litera6.setCharacterSize(40);
    litera6.setFillColor(Color::Black);
    litera6.setPosition(x2 + 450, y2 + 440);

    tekst19.setFont(sansExtraBold);
    tekst19.setString("Lewo: ");
    tekst19.setCharacterSize(40);
    tekst19.setFillColor(Color::Yellow);
    tekst19.setPosition(x2 + 50, y2 + 510);

    rectangle7 = RectangleShape(Vector2f(75, 50));
    rectangle7.setFillColor(Color::White);
    rectangle7.setPosition(x2 + 190, y2 + 510);

    litera7.setFont(sansExtraBold);
    litera7.setString(ster[playersKeybindings[1].left]);
    litera7.setCharacterSize(40);
    litera7.setFillColor(Color::Black);
    litera7.setPosition(x2 + 200, y2 + 510);

    tekst20.setFont(sansExtraBold);
    tekst20.setString("Prawo: ");
    tekst20.setCharacterSize(40);
    tekst20.setFillColor(Color::Yellow);
    tekst20.setPosition(x2 + 290, y2 + 510);

    rectangle8 = RectangleShape(Vector2f(75, 50));
    rectangle8.setFillColor(Color::White);
    rectangle8.setPosition(x2 + 440, y2 + 510);

    litera8.setFont(sansExtraBold);
    litera8.setString(ster[playersKeybindings[1].right]);
    litera8.setCharacterSize(40);
    litera8.setFillColor(Color::Black);
    litera8.setPosition(x2 + 450, y2 + 510);

    tekst32.setFont(sansExtraBold);
    tekst32.setString("Strzal: ");
    tekst32.setCharacterSize(40);
    tekst32.setFillColor(Color::Yellow);
    tekst32.setPosition(x2 + 140, y2 + 580);

    rectangle18 = RectangleShape(Vector2f(75, 50));
    rectangle18.setFillColor(Color::White);
    rectangle18.setPosition(x2 + 290, y2 + 580);

    litera18.setFont(sansExtraBold);
    litera18.setString(ster[playersKeybindings[1].shot]);
    litera18.setCharacterSize(40);
    litera18.setFillColor(Color::Black);
    litera18.setPosition(x2 + 300, y2 + 580);

    //------------------------------------Niebieski     3
    tekst21.setFont(sansExtraBold);
    tekst21.setString("Gracz 3");
    tekst21.setPosition(x2 + 570, y2 + 60);
    tekst21.setCharacterSize(60);
    tekst21.setFillColor(Color::Blue);

    tekst22.setFont(sansExtraBold);
    tekst22.setString("Przod: ");
    tekst22.setCharacterSize(40);
    tekst22.setFillColor(Color::Blue);
    tekst22.setPosition(x2 + 530, y2 + 150);

    rectangle9 = RectangleShape(Vector2f(75, 50));
    rectangle9.setFillColor(Color::White);
    rectangle9.setPosition(x2 + 670, y2 + 150);

    litera9.setFont(sansExtraBold);
    litera9.setString(ster[playersKeybindings[2].up]);
    litera9.setCharacterSize(40);
    litera9.setFillColor(Color::Black);
    litera9.setPosition(x2 + 680, y2 + 150);

    tekst23.setFont(sansExtraBold);
    tekst23.setString("Tyl: ");
    tekst23.setCharacterSize(40);
    tekst23.setFillColor(Color::Blue);
    tekst23.setPosition(x2 + 770, y2 + 150);

    rectangle10 = RectangleShape(Vector2f(75, 50));
    rectangle10.setFillColor(Color::White);
    rectangle10.setPosition(x2 + 920, y2 + 150);

    litera10.setFont(sansExtraBold);
    litera10.setString(ster[playersKeybindings[2].down]);
    litera10.setCharacterSize(40);
    litera10.setFillColor(Color::Black);
    litera10.setPosition(x2 + 930, y2 + 150);

    tekst24.setFont(sansExtraBold);
    tekst24.setString("Lewo: ");
    tekst24.setCharacterSize(40);
    tekst24.setFillColor(Color::Blue);
    tekst24.setPosition(x2 + 530, y2 + 220);

    rectangle11 = RectangleShape(Vector2f(75, 50));
    rectangle11.setFillColor(Color::White);
    rectangle11.setPosition(x2 + 670, y2 + 220);

    litera11.setFont(sansExtraBold);
    litera11.setString(ster[playersKeybindings[2].left]);
    litera11.setCharacterSize(40);
    litera11.setFillColor(Color::Black);
    litera11.setPosition(x2 + 680, y2 + 220);

    tekst25.setFont(sansExtraBold);
    tekst25.setString("Prawo: ");
    tekst25.setCharacterSize(40);
    tekst25.setFillColor(Color::Blue);
    tekst25.setPosition(x2 + 770, y2 + 220);

    rectangle12 = RectangleShape(Vector2f(75, 50));
    rectangle12.setFillColor(Color::White);
    rectangle12.setPosition(x2 + 920, y2 + 220);

    litera12.setFont(sansExtraBold);
    litera12.setString(ster[playersKeybindings[2].right]);
    litera12.setCharacterSize(40);
    litera12.setFillColor(Color::Black);
    litera12.setPosition(x2 + 930, y2 + 220);

    tekst33.setFont(sansExtraBold);
    tekst33.setString("Strzal: ");
    tekst33.setCharacterSize(40);
    tekst33.setFillColor(Color::Blue);
    tekst33.setPosition(x2 + 620, y2 + 290);

    rectangle19 = RectangleShape(Vector2f(75, 50));
    rectangle19.setFillColor(Color::White);
    rectangle19.setPosition(x2 + 770, y2 + 290);

    litera19.setFont(sansExtraBold);
    litera19.setString(ster[playersKeybindings[2].shot]);
    litera19.setCharacterSize(40);
    litera19.setFillColor(Color::Black);
    litera19.setPosition(x2 + 780, y2 + 290);

    //---------------------------------------Zielony     4
    tekst26.setFont(sansExtraBold);
    tekst26.setString("Gracz 4");
    tekst26.setPosition(x2 + 570, y2 + 350);
    tekst26.setCharacterSize(60);
    tekst26.setFillColor(Color::Green);

    tekst27.setFont(sansExtraBold);
    tekst27.setString("Przod: ");
    tekst27.setCharacterSize(40);
    tekst27.setFillColor(Color::Green);
    tekst27.setPosition(x2 + 530, y2 + 440);

    rectangle13 = RectangleShape(Vector2f(75, 50));
    rectangle13.setFillColor(Color::White);
    rectangle13.setPosition(x2 + 670, y2 + 440);

    litera13.setFont(sansExtraBold);
    litera13.setString(ster[playersKeybindings[3].up]);
    litera13.setCharacterSize(40);
    litera13.setFillColor(Color::Black);
    litera13.setPosition(x2 + 680, y2 + 440);

    tekst28.setFont(sansExtraBold);
    tekst28.setString("Tyl: ");
    tekst28.setCharacterSize(40);
    tekst28.setFillColor(Color::Green);
    tekst28.setPosition(x2 + 770, y2 + 440);

    rectangle14 = RectangleShape(Vector2f(75, 50));
    rectangle14.setFillColor(Color::White);
    rectangle14.setPosition(x2 + 920, y2 + 440);

    litera14.setFont(sansExtraBold);
    litera14.setString(ster[playersKeybindings[3].down]);
    litera14.setCharacterSize(40);
    litera14.setFillColor(Color::Black);
    litera14.setPosition(x2 + 930, y2 + 440);

    tekst29.setFont(sansExtraBold);
    tekst29.setString("Lewo: ");
    tekst29.setCharacterSize(40);
    tekst29.setFillColor(Color::Green);
    tekst29.setPosition(x2 + 530, y2 + 510);

    rectangle15 = RectangleShape(Vector2f(75, 50));
    rectangle15.setFillColor(Color::White);
    rectangle15.setPosition(x2 + 670, y2 + 510);

    litera15.setFont(sansExtraBold);
    litera15.setString(ster[playersKeybindings[3].left]);
    litera15.setCharacterSize(40);
    litera15.setFillColor(Color::Black);
    litera15.setPosition(x2 + 680, y2 + 510);

    tekst30.setFont(sansExtraBold);
    tekst30.setString("Prawo: ");
    tekst30.setCharacterSize(40);
    tekst30.setFillColor(Color::Green);
    tekst30.setPosition(x2 + 770, y2 + 510);

    rectangle16 = RectangleShape(Vector2f(75, 50));
    rectangle16.setFillColor(Color::White);
    rectangle16.setPosition(x2 + 920, y2 + 510);

    litera16.setFont(sansExtraBold);
    litera16.setString(ster[playersKeybindings[3].right]);
    litera16.setCharacterSize(40);
    litera16.setFillColor(Color::Black);
    litera16.setPosition(x2 + 930, y2 + 510);

    tekst34.setFont(sansExtraBold);
    tekst34.setString("Strzal: ");
    tekst34.setCharacterSize(40);
    tekst34.setFillColor(Color::Green);
    tekst34.setPosition(x2 + 620, y2 + 580);

    rectangle20 = RectangleShape(Vector2f(75, 50));
    rectangle20.setFillColor(Color::White);
    rectangle20.setPosition(x2 + 770, y2 + 580);
    
    litera20.setFont(sansExtraBold);
    litera20.setString(ster[playersKeybindings[3].shot]);
    litera20.setCharacterSize(40);
    litera20.setFillColor(Color::Black);
    litera20.setPosition(x2 + 780, y2 + 580);

    tekst35.setFont(sansExtraBold);
    tekst35.setString("Nacisnij przycisk nastepnie wybierz klawisz aby zamienic ustawienia");
    tekst35.setCharacterSize(25);
    tekst35.setFillColor(Color::Black);
    tekst35.setPosition(x2 + 45, y2 + 20);

    //-----------------------------------------------------------Graj
    vector<string> names = getLevelNames();

    levelNames.reserve(names.size());
    box.reserve(names.size());
    for (int i = 0; i < names.size(); i++)
    {
        Text level;

        level.setFont(sansExtraBold);
        level.setCharacterSize(30);
        level.setString(names[i]);
        level.setPosition(400, 300 + i % 6 * 50);

        levelNames.push_back(level);

        RectangleShape kw(Vector2f(500, 35));
        kw.setFillColor(Color(59, 101, 46));
        kw.setPosition(400, 300 + i % 6 * 50);

        box.push_back(kw);


        Sprite PlayA(*button1);
        PlayA.setPosition(810, 303 + i % 6 * 50);

        play.push_back(PlayA);


        Sprite CogA(*button2);
        CogA.setPosition(850, 303 + i % 6 * 50);

        cog.push_back(CogA);
    }

    tekst36.setFont(sansExtraBold);
    tekst36.setString("WYBOR MAPY!!!");
    tekst36.setCharacterSize(60);
    tekst36.setFillColor(Color::Black);
    tekst36.setPosition(410, 170);

    tekst37.setFont(sansExtraBold);
    tekst37.setString(to_string(z2));
    tekst37.setCharacterSize(40);
    tekst37.setFillColor(Color::Black);
    tekst37.setPosition(625, 700);

    tekst38.setFont(sansExtraBold);
    tekst38.setString("Uzyj kalawiszy \nA i D aby \nzmienic strone \nwyswietlanych \nmap");
    tekst38.setCharacterSize(30);
    tekst38.setFillColor(Color::Black);
    tekst38.setPosition(130, 350);

    tekst39.setFont(sansExtraBold);
    tekst39.setString("Wybierz \nzebatke aby \nedytowac \ndana mape \nWcisnij drugi \nprzycisk \naby grac");
    tekst39.setCharacterSize(30);
    tekst39.setFillColor(Color::Black);
    tekst39.setPosition(925, 300);

    tekst40.setFont(sansExtraBold);
    tekst40.setString("+");
    tekst40.setCharacterSize(80);
    tekst40.setFillColor(Color::White);
    tekst40.setPosition(927, 623);

    shape1 = CircleShape(25);
    shape1.setFillColor(Color(0, 0, 0, 0));
    shape1.setOutlineColor(Color::White);
    shape1.setOutlineThickness(7);
    shape1.setPosition(925, 650);

    X1 = Sprite(*X);

    shape = CircleShape(25);
    shape.setFillColor(Color::White);

    okno = 0;
    m = -0.5;
    m2 = -1.3;
    start = 0;
    start2 = 255;
}

Scene* Menu::processEvent(sf::RenderWindow& window, sf::Event& event)
{
    if (okno == 4 && event.type == Event::KeyPressed) {
        if (event.key.code == 3) { if ((z2 * 6) < levelNames.size()) { z2++; } }
        if (event.key.code == 0) { if (z2 != 1) { z2--; } }
    }

	return nullptr;
}

Scene* Menu::doCalculations(sf::RenderWindow& window, float deltaTime)
{
    Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
    int x = mousePosition.x;
    int y = mousePosition.y;

    switch (okno) {
    case 0: //pierwsze okno
        window.draw(Tlo1);
        Tlo1.move(0, m);
        if (Tlo1.getPosition().y <= -200) { m = 0.5; }
        if (Tlo1.getPosition().y >= 0) { m = -0.5; }

        window.draw(Tytol1);
        window.draw(tekst);
        window.draw(tekst2);


        //animacja
        if (Mouse::isButtonPressed(Mouse::Left)) {
            start = 1;

        }

        switch (start) {
        case 1:

            if (Tytol1.getPosition().y >= 50) {
                Tytol1.move(0, m2);
                m2 = m2 + 0.003;

                tekst2.setFillColor(Color(255, 0, 0, start2));
                tekst.setFillColor(Color(255, 0, 0, start2));
                if (start2 != 0) { start2 = start2 - 3; }
            }
            else {
                Tytol1.move(0, 0); okno = 1;
            }
            break;
        }

        break;
    case 1://menu

        Tytol1.setPosition(395, 50);//55
        window.draw(Tlo1);
        Tlo1.move(0, m);
        if (Tlo1.getPosition().y <= -200) { m = 0.5; }
        if (Tlo1.getPosition().y >= 0) { m = -0.5; }
        window.draw(Tytol1);

        window.draw(convex);
        window.draw(tekst3);

        window.draw(convex3);
        window.draw(tekst5);

        window.draw(convex4);
        window.draw(tekst6);


        if (x >= 472.5 && y >= 320 && x <= 472.5 + 305 && y <= 320 + 120) {
            convex.setFillColor(Color::Blue);
            convex.setOutlineColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left)) { okno = 4; }
        }
        else {
            convex.setFillColor(Color(150, 50, 250));
            convex.setOutlineColor(Color(250, 150, 100));
        }
        if (x >= 497.5 && y >= 500 && x <= 497.5 + 255 && y <= 500 + 100) {
            convex3.setFillColor(Color::Blue);
            convex3.setOutlineColor(Color::Green);
            if (Mouse::isButtonPressed(Mouse::Left)) { okno = 3; }
        }
        else {
            convex3.setFillColor(Color(150, 50, 250));
            convex3.setOutlineColor(Color(250, 150, 100));
        }
        if (x >= 25 && y >= 800 && x <= 25 + 185 && y <= 800 + 70) {
            convex4.setOutlineColor(Color(255, 215, 0));
            if (Mouse::isButtonPressed(Mouse::Left)) { okno = 2; }
        }
        else {
            convex4.setOutlineColor(Color(32, 32, 32));
        }

        break;
    case 2://Tworcy
        X1.setPosition(1075, 250);
        shape.setPosition(1075, 250);
        Tytol1.setPosition(395, 50);
        window.draw(Tlo1);
        Tlo1.move(0, m);
        if (Tlo1.getPosition().y <= -200) { m = 0.5; }
        if (Tlo1.getPosition().y >= 0) { m = -0.5; }
        window.draw(Tytol1);

        window.draw(convex5);
        window.draw(tekst7);
        window.draw(tekst8);
        window.draw(tekst9);
        window.draw(tekst10);

        if (x >= 1075 && y >= 250 && x <= 1075 + 50 && y <= 250 + 50) { window.draw(shape);  if (Mouse::isButtonPressed(Mouse::Left)) { okno = 1; } }
        window.draw(X1);

        break;
    case 3://Ustawienia
        convex6.setFillColor(Color(69, 69, 69));
        convex6.setOutlineColor(Color(233, 116, 81));
        X1.setPosition(1130, 70);
        shape.setPosition(1130, 70);
        window.draw(Tlo1);
        Tlo1.move(0, m);
        if (Tlo1.getPosition().y <= -200) { m = 0.5; }
        if (Tlo1.getPosition().y >= 0) { m = -0.5; }

        window.draw(convex6);

        window.draw(tekst11);
        window.draw(tekst12);
        window.draw(rectangle1);
        window.draw(litera1);
        window.draw(tekst13);
        window.draw(rectangle2);
        window.draw(litera2);
        window.draw(tekst14);
        window.draw(rectangle3);
        window.draw(litera3);
        window.draw(tekst15);
        window.draw(rectangle4);
        window.draw(litera4);
        window.draw(tekst31);
        window.draw(rectangle17);
        window.draw(litera17);

        window.draw(tekst16);
        window.draw(tekst17);
        window.draw(rectangle5);
        window.draw(litera5);
        window.draw(tekst18);
        window.draw(rectangle6);
        window.draw(litera6);
        window.draw(tekst19);
        window.draw(rectangle7);
        window.draw(litera7);
        window.draw(tekst20);
        window.draw(rectangle8);
        window.draw(litera8);
        window.draw(tekst32);
        window.draw(rectangle18);
        window.draw(litera18);

        window.draw(tekst21);
        window.draw(tekst22);
        window.draw(rectangle9);
        window.draw(litera9);
        window.draw(tekst23);
        window.draw(rectangle10);
        window.draw(litera10);
        window.draw(tekst24);
        window.draw(rectangle11);
        window.draw(litera11);
        window.draw(tekst25);
        window.draw(rectangle12);
        window.draw(litera12);
        window.draw(tekst33);
        window.draw(rectangle19);
        window.draw(litera19);

        window.draw(tekst26);
        window.draw(tekst27);
        window.draw(rectangle13);
        window.draw(litera13);
        window.draw(tekst28);
        window.draw(rectangle14);
        window.draw(litera14);
        window.draw(tekst29);
        window.draw(rectangle15);
        window.draw(litera15);
        window.draw(tekst30);
        window.draw(rectangle16);
        window.draw(litera16);
        window.draw(tekst34);
        window.draw(rectangle20);
        window.draw(litera20);

        window.draw(tekst35);

        if (Mouse::isButtonPressed(Mouse::Left)) {//x2 = 120; y2 = 125;

            if (x >= 310 && y >= 275 && x <= 385 && y <= 325) {//gracz 1   w
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[0].up = event.key.code;
                        litera1.setString(ster[playersKeybindings[0].up]);
                        break;
                    }
                }
            }
            if (x >= 560 && y >= 275 && x <= 635 && y <= 325) {//gracz 1  s
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[0].down = event.key.code;
                        litera2.setString(ster[playersKeybindings[0].down]);
                        break;
                    }
                }
            }
            if (x >= 310 && y >= 345 && x <= 385 && y <= 395) {//gracz 1  a
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[0].left = event.key.code;
                        litera3.setString(ster[playersKeybindings[0].left]);
                        break;
                    }
                }
            }
            if (x >= 560 && y >= 345 && x <= 635 && y <= 395) {//gracz 1  d
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[0].right = event.key.code;
                        litera4.setString(ster[playersKeybindings[0].right]);
                        break;
                    }
                }
            }
            if (x >= 410 && y >= 415 && x <= 485 && y <= 465) {//gracz 1  e   
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[0].shot = event.key.code;
                        litera17.setString(ster[playersKeybindings[0].shot]);
                        break;
                    }
                }
            }
            if (x >= 310 && y >= 565 && x <= 380 && y <= 615) {//gracz 2  w
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[1].up = event.key.code;
                        litera5.setString(ster[playersKeybindings[1].up]);
                        break;
                    }
                }
            }
            if (x >= 560 && y >= 565 && x <= 635 && y <= 615) {//gracz 2  s
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[1].down = event.key.code;
                        litera6.setString(ster[playersKeybindings[1].down]);
                        break;
                    }
                }
            }
            if (x >= 310 && y >= 635 && x <= 380 && y <= 685) {//gracz 2  a
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[1].left = event.key.code;
                        litera7.setString(ster[playersKeybindings[1].left]);
                        break;
                    }
                }
            }
            if (x >= 560 && y >= 635 && x <= 685 && y <= 685) {//gracz 2  d
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[1].right = event.key.code;
                        litera8.setString(ster[playersKeybindings[1].right]);
                        break;
                    }
                }
            }
            if (x >= 410 && y >= 705 && x <= 485 && y <= 755) {//gracz 2  e
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[1].shot = event.key.code;
                        litera18.setString(ster[playersKeybindings[1].shot]);
                        break;
                    }
                }
            }
            if (x >= 790 && y >= 275 && x <= 865 && y <= 325) {//gracz 3  w 
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[2].up = event.key.code;
                        litera9.setString(ster[playersKeybindings[2].up]);
                        break;
                    }
                }
            }
            if (x >= 1040 && y >= 275 && x <= 1115 && y <= 325) {//gracz 3  s
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[2].down = event.key.code;
                        litera10.setString(ster[playersKeybindings[2].down]);
                        break;
                    }
                }
            }
            if (x >= 790 && y >= 345 && x <= 865 && y <= 395) {//gracz 3  a
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[2].left = event.key.code;
                        litera11.setString(ster[playersKeybindings[2].left]);
                        break;
                    }
                }
            }
            if (x >= 1040 && y >= 345 && x <= 1115 && y <= 395) {//gracz 3  d
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[2].right = event.key.code;
                        litera12.setString(ster[playersKeybindings[2].right]);
                        break;
                    }
                }
            }
            if (x >= 890 && y >= 415 && x <= 965 && y <= 465) {//gracz 3  e
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[2].shot = event.key.code;
                        litera19.setString(ster[playersKeybindings[2].shot]);
                        break;
                    }
                }
            }
            if (x >= 790 && y >= 565 && x <= 865 && y <= 615) {//gracz 4  w
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[3].up = event.key.code;
                        litera13.setString(ster[playersKeybindings[3].up]);
                        break;
                    }
                }
            }
            if (x >= 1040 && y >= 565 && x <= 1115 && y <= 615) {//gracz 4  s
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[3].down = event.key.code;
                        litera14.setString(ster[playersKeybindings[3].down]);
                        break;
                    }
                }
            }
            if (x >= 790 && y >= 635 && x <= 865 && y <= 685) {//gracz 4  a
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[3].left = event.key.code;
                        litera15.setString(ster[playersKeybindings[3].left]);
                        break;
                    }
                }
            }
            if (x >= 1040 && y >= 635 && x <= 1115 && y <= 685) {//gracz 4  d
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[3].right = event.key.code;
                        litera16.setString(ster[playersKeybindings[3].right]);
                        break;
                    }
                }
            }
            if (x >= 890 && y >= 705 && x <= 965 && y <= 755) {//gracz 4  e
                while (true) {
                    window.pollEvent(event);
                    if (event.type == Event::KeyPressed) {
                        playersKeybindings[3].shot = event.key.code;
                        litera20.setString(ster[playersKeybindings[3].shot]);
                        break;
                    }
                }
            }

        }

        if (x >= 1130 && y >= 70 && x <= 1130 + 50 && y <= 70 + 50) { window.draw(shape);  if (Mouse::isButtonPressed(Mouse::Left)) { okno = 1; } }
        window.draw(X1);

        break;
    case 4://Graj
        convex6.setFillColor(Color(79, 121, 66));
        convex6.setOutlineColor(Color(233, 116, 81));

        X1.setPosition(1130, 70);
        shape.setPosition(1130, 70);
        window.draw(Tlo1);
        Tlo1.move(0, m);
        if (Tlo1.getPosition().y <= -200) { m = 0.5; }
        if (Tlo1.getPosition().y >= 0) { m = -0.5; }

        window.draw(convex6);

        window.draw(tekst36);
        window.draw(tekst37);
        window.draw(tekst38);
        window.draw(tekst39);
        for (int i = 6 * (z2 - 1); i < levelNames.size() && i < z2 * 6; i++)
        {

            window.draw(box[i]);
            window.draw(levelNames[i]);
            window.draw(cog[i]);
            window.draw(play[i]);
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {

            for (int i = 6 * (z2 - 1); i < levelNames.size() && i < z2 * 6; i++)//Przechodzenie do gry/edytora
            {
                if (x >= 810 && y >= 303 + i % 6 * 50 && x <= 840 && y <= 333 + i % 6 * 50) { return new Arena(Level(levelNames[i].getString())); }
                if (x >= 850 && y >= 303 + i % 6 * 50 && x <= 880 && y <= 333 + i % 6 * 50) { return new Editor(Level(levelNames[i].getString())); }
            }

        }
        
        tekst37.setString(to_string(z2));

        if (x >= 1130 && y >= 70 && x <= 1130 + 50 && y <= 70 + 50) { window.draw(shape);  if (Mouse::isButtonPressed(Mouse::Left)) { okno = 1; } }
        window.draw(X1);

        if (x >= 925 && y >= 650 && x <= 925 + 50 && y <= 650 + 50) {
            tekst40.setFillColor(Color::Green);  if (Mouse::isButtonPressed(Mouse::Left)) { return new Editor(Level()); }
        }
        else { tekst40.setFillColor(Color::White); }
        window.draw(tekst40);

        break;
    }

    // window.draw(sprite);




	return nullptr;
}

void Menu::draw(sf::RenderWindow& window)
{
}