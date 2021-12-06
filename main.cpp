#include <iostream>
#include <windows.h>
#include <ctime>
#include <bitset>
using namespace std;

int boss_health;
int boss_shield;

bool QTE(int a)
{
    srand(time(0));
    string words[] = {"goat", "coat", "boat", "bear", "flux", "floppa", "card", "current", "word", "hdmi"};
    int a = (rand() % 1000) % 10;
    cout << words[a] << endl << "You need to type this word as fast as you can!\n";
    int start = clock();
    string s;
    cin >> s;
    int _end = clock();
    if(s == words[a] && _end - start <= a){
        return true;
    }
    else{
        return false;
    }
    return 0;
}

bool oneshot()
{
    srand(time(0));
    bitset<100> bs;
    bs.set();
    bs[7] = bs[1] = bs[17] = bs[73] = bs[25] = bs[69] = bs[34] = bs[99] = bs[0] = bs[57] = 0;
    int a = rand() % 100;
    if(bs[a]) return false;
    else return true;

}

bool evade()
{
    srand(time(0));
    bitset<100> bs;
    bs.set();
    bs[7] = bs[1] = bs[17] = bs[23] = bs[84] = bs[69] = bs[34] = bs[99] = bs[0] = bs[57] = bs[25] = bs[43] = bs[36] = bs[72] = bs[53] = bs[30] = bs[76] = bs[20] = bs[47] = bs[94];
    int a = rand() % 100;
    if(bs[a]) return false;
    else return true;

}
void print_names(string name)
{
    cout << "               " << name << "                                          Enemy         " <<  endl;
}

int get_number()
{
    int number;
    cin >> number;
    return number;
}

class Warrior
{
private:
    string m_name;
    int m_armour;
public:
    int m_health;
    int m_damage;
    int m_flasks;
    int m_DDflasks;

    void setParameter(string name, int health, int damage, int armour, int flasks)
    {
        m_health = health;
        m_damage = damage;
        m_armour = armour;
        m_name = name;
        m_flasks = flasks;
    }

    void print_Player()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << " " <<
            "Flasks: " << m_flasks << "         ";
    }

    void print_Enemy()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << " " <<
            "Flasks: " << m_flasks << endl;
    }
    void takeDamage(int dmg)
    {
        srand(time(0));
        int a = rand() % 10;
        int b = 1 + rand() % 2;
        if(b == 1) a = -a;
        dmg = dmg - (m_armour / 10) + a;
        m_health -= dmg;
    }

    void heal(int number_of_flasks, int hp_heal, int max_hp)
    {
        if(number_of_flasks != 0 && m_health < max_hp - hp_heal){
            m_health += hp_heal;
            m_flasks--;
            if(m_health > max_hp) m_health = max_hp;
        }
        else if (number_of_flasks == 0){
            cout << " You don't have any flasks!";
        }
        else{
            m_health = max_hp;
        }
    }
    void ii_heal(int number_of_flasks)
    {
        if(number_of_flasks != 0 && m_health < 100){
            m_health += 15;
            m_flasks--;
            if(m_health > 100) m_health = 100;
        }
    }
};

class Healer
{
private:
    string m_name;
    int m_armour;
public:
    int m_health;
    int m_damage;
    int m_flasks;
    int m_invulnerability;
    int m_reincarnation;

    void setParameter(string name, int health, int damage, int armour, int flasks)
    {
        m_health = health;
        m_damage = damage;
        m_armour = armour;
        m_name = name;
        m_flasks = flasks;
    }

    void print_Player()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << " " <<
            "Flasks: " << m_flasks << "         ";
    }

    void print_Enemy()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << endl;
    }
    void takeDamage(int dmg)
    {
        srand(time(0));
        int a = rand() % 10;
        int b = 1 + rand() % 2;
        if(b == 1) a = -a;
        dmg = dmg - (m_armour / 10) + a;
        m_health -= dmg;
    }

   void heal(int number_of_flasks, int hp_heal, int max_hp)
    {
        if(number_of_flasks != 0 && m_health < max_hp - hp_heal){
            m_health += hp_heal;
            m_flasks--;
            if(m_health > max_hp) m_health = max_hp;
        }
        else if (number_of_flasks == 0){
            cout << " You don't have any flasks!";
        }
        else{
            m_health = max_hp;
        }
    }
    void ii_heal(int number_of_flasks)
    {
        if(number_of_flasks != 0 && m_health < 100){
            m_health += 15;
            m_flasks--;
            if(m_health > 100) m_health = 100;
        }
    }
};

class Assassin
{
private:
    string m_name;
    int m_armour;
public:
    int m_health;
    int m_damage;
    int m_doubledamage;
    int m_evasion;
    int m_reduction;

    void setParameter(string name, int health, int damage, int armour, int double_damage)
    {
        m_health = health;
        m_damage = damage;
        m_armour = armour;
        m_name = name;
        m_doubledamage = double_damage;
    }

    void print_Player()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << " " <<
            "DD hits: " << m_doubledamage << "         ";
    }

    void print_Enemy()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << endl;
    }
    void takeDamage(int dmg)
    {
        srand(time(0));
        int a = rand() % 10;
        int b = 1 + rand() % 2;
        if(b == 1) a = -a;
        dmg = dmg - (m_armour / 10) + a;
        m_health -= dmg;
    }

};

class Boss
{
private:
    string m_name;
    int m_armour;
public:
    int m_shield;
    int m_health;
    int m_damage;

     void setParameter(string name, int health, int damage, int armour, int shield)
    {
        m_health = health;
        m_damage = damage;
        m_armour = armour;
        m_name = name;
        m_shield = shield;
    }

    void takeDamage(int dmg)
    {
        srand(time(0));
        int a = rand() % 10;
        int b = 1 + rand() % 2;
        if(b == 1) a = -a;
        dmg = dmg - (m_armour / 10) + a;
        if(m_shield > 0) m_shield -= dmg;
        else m_health -= dmg;
    }

    void print_Enemy()
    {
        cout << "HP: " << m_health << " " <<
            "DMG: " << m_damage << " " <<
            "ARM: " << m_armour << " " <<
            "Shield: " << m_shield << endl;
    }

    void minus_armour(int reduced_armour)
    {
        m_armour -= reduced_armour;
    }

};

void move_doneWarriorBoss(string name, Warrior Player, Boss Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

void move_doneAssassinBoss(string name, Assassin Player, Boss Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

void move_doneHealerBoss(string name, Healer Player, Boss Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

void move_doneWarrior(string name, Warrior Player, Warrior Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

void move_doneHealear(string name, Healer Player, Warrior Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

void move_doneAssassin(string name, Assassin Player, Warrior Enemy)
{
    system("cls");
    print_names(name);
    Player.print_Player();
    Enemy.print_Enemy();
}

bool game1_lvl_1(string name, Warrior Player, Warrior Enemy, int turn)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                if(get_number() == 1){
                    Enemy.takeDamage(Player.m_damage);}
                else if (Player.m_flasks != 0){
                    Player.heal(Player.m_flasks, 25, 100);}
                    else{
                        cout << "\nYou out of flasks or missed the button! Be careful!\n";
                        Sleep(1300);
                    }
                move_doneWarrior(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneWarrior(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    Player.takeDamage(20);
                    move_doneWarrior(name, Player, Enemy);
                    cout << "\nOuch! Enemy just attacked you!\n"; }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                Sleep(1000);
                turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game2_lvl_1(string name, Healer Player, Warrior Enemy, int turn)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                if(get_number() == 1){
                    Enemy.takeDamage(Player.m_damage);}
                else if (Player.m_flasks != 0){
                    Player.heal(Player.m_flasks, 25, 100);}
                    else{
                        cout << "\nYou out of flasks or missed the button! Be careful!\n";
                        Sleep(1300);
                    }
                move_doneHealear(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneHealear(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    Player.takeDamage(20);
                    move_doneHealear(name, Player, Enemy);
                    cout << "\nOuch! Enemy just attacked you!\n"; }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                Sleep(1000);
                turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game3_lvl_1(string name, Assassin Player, Warrior Enemy, int turn)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int a;
                cin >> a;
                if(a == 1){
                    Enemy.takeDamage(Player.m_damage);}
                else if(a == 2 && Player.m_doubledamage != 0){
                    Enemy.takeDamage(2 * Player.m_damage);
                    Player.m_doubledamage--;
                    cout << "\nYou just dealt double damage!\n";
                    Sleep(1300);

                }
                else{
                    cout << "\nYou can't do it now!\n";
                    Sleep(1300);
                }
                move_doneAssassin(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneAssassin(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    Player.takeDamage(20);
                    move_doneAssassin(name, Player, Enemy);
                    cout << "\nOuch! Enemy just attacked you!\n"; }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to deal double damage!\n";
                Sleep(1000);
                turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game1_lvl_2(string name, Warrior Player, Warrior Enemy, int turn, int upgrade)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int number = get_number();
                if(number == 1){
                    if(QTE(4000)){
                        Enemy.takeDamage(Player.m_damage);
                        cout << "\nGood job!\n";
                        Sleep(1300);
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
                else if (number == 2 && Player.m_flasks != 0){
                    if(upgrade == 2){
                            Player.heal(Player.m_flasks, 25, 115);
                    }
                    else{
                        Player.heal(Player.m_flasks, 25, 100);
                    }
                }
                else{
                    cout << "\nYou out of flasks or missed the button! Be careful!\n";
                    Sleep(1300);
                }
                move_doneWarrior(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneWarrior(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    Player.takeDamage(20);
                    move_doneWarrior(name, Player, Enemy);
                    cout << "\nOuch! Enemy just attacked you!\n"; }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                Sleep(1000);
                turn = 0;
            }
        }

        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game2_lvl_2(string name, Healer Player, Warrior Enemy, int turn, int upgrade, int hp_heal)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int number = get_number();
                if(number == 1){
                    if(QTE(4000)){
                    Enemy.takeDamage(Player.m_damage);
                    cout << "\nGood job!\n";
                    Sleep(1300);
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
                else if (Player.m_flasks != 0 && number == 2){
                    Player.heal(Player.m_flasks, hp_heal, 100);
                }
                else{
                    cout << "\nYou out of flasks or missed the button! Be careful!\n";
                    Sleep(1300);
                }
                move_doneHealear(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneHealear(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    Player.takeDamage(20);
                    move_doneHealear(name, Player, Enemy);
                    cout << "\nOuch! Enemy just attacked you!\n"; }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                Sleep(1000);
                turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game3_lvl_2(string name, Assassin Player, Warrior Enemy, int turn, int upgrade)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int a;
                cin >> a;
                if(a == 1){
                    if(QTE(4000)){
                    Enemy.takeDamage(Player.m_damage);}
                    else{
                        cout << "\nYou missed your hit!";
                        Sleep(1300);
                    }
                }
                else if(a == 2 && Player.m_doubledamage != 0){
                    Enemy.takeDamage(2 * Player.m_damage);
                    Player.m_doubledamage--;
                    cout << "\nYou just dealt double damage!\n";
                    Sleep(1300);

                }
                else{
                    cout << "\nYou can't do it now!\n";
                    Sleep(1300);
                }
                move_doneAssassin(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(Enemy.m_health <= 80 && Enemy.m_flasks != 0) {
                    Enemy.ii_heal(Enemy.m_flasks);
                    move_doneAssassin(name, Player, Enemy);
                    cout << "\nEnemy healed himself\n"; }
                else{
                    if(upgrade == 2){
                        if(!evade()){
                            Player.takeDamage(Enemy.m_damage);
                            cout << "\nOuch! Enemy just attacked you!\n";
                        }
                        else{
                            Player.takeDamage(0);
                            cout << "\nYou have dodged enemy's hit!\n";

                        }
                    }
                    else{
                        Player.takeDamage(Enemy.m_damage);
                        cout << "\nOuch! Enemy just attacked you!\n";
                    }
                    move_doneAssassin(name, Player, Enemy);
                }
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to deal double damage!\n";
                Sleep(1000);
                turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game1_lvl_3(string name, Warrior Player, Boss Enemy, int turn, int upgrade, int skill)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int number = get_number();
                if(number == 1){
                    if(QTE(3000)){
                        if(skill == 2){
                            if(oneshot()) {
                                cout << "Wow! One-Punch Man moment lol";
                                Sleep(1300);
                                Enemy.m_health = 0;
                            }
                            else{
                                Enemy.takeDamage(Player.m_damage);
                                cout << "\nGood job!\n";
                                Sleep(1300);
                            }
                        }
                        else{
                            Enemy.takeDamage(Player.m_damage);
                            cout << "\nGood job!\n";
                            Sleep(1300);
                        }
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
                else if (number == 2 && Player.m_flasks != 0){
                    if(upgrade == 2){
                            if(skill == 3) Player.heal(Player.m_flasks, 25, 130);
                            else Player.heal(Player.m_flasks, 25, 115);
                    }
                    else{
                        if(skill == 3) Player.heal(Player.m_flasks, 25, 115);
                        else Player.heal(Player.m_flasks, 25, 100);
                    }
                }
                else if(skill == 1 && number == 3 && Player.m_DDflasks != 0){
                    if(QTE()){
                        Enemy.takeDamage(2 * Player.m_damage);
                        Player.m_DDflasks--;
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
                else{
                    cout << "\nYou out of flasks or missed the button! Be careful!\n";
                    Sleep(1300);
                }
                move_doneWarriorBoss(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                Player.takeDamage(Enemy.m_damage);
                move_doneWarriorBoss(name, Player, Enemy);
                cout << "\nOuch! Enemy just attacked you!\n";
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                if(skill == 1 && Player.m_DDflasks != 0) cout << "You can deal double damage " << Player.m_DDflasks << " times by typing \"3\"!\n";
                else if(skill == 1 && Player.m_DDflasks == 0) cout << "\nYou can no longer deal double damage!";
                Sleep(1000);
                turn = 0;
            }
        }

        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game2_lvl_3(string name, Healer Player, Boss Enemy, int turn, int upgrade, int skill, int hp_heal, bool invicible)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int number = get_number();
                if(number == 1){
                    if(QTE(3000)){
                        Enemy.takeDamage(Player.m_damage);
                        cout << "\nGood job!\n";
                        Sleep(1300);
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
                else if (number == 2 && Player.m_flasks != 0){
                    if(skill == 3) Player.heal(Player.m_flasks, hp_heal, 115);
                    else Player.heal(Player.m_flasks, hp_heal, 100);
                }
                else if(skill == 1 && number == 3 && Player.m_invulnerability != 0){
                    if(QTE(3000)){
                        invicible = true;
                        cout << "\nYou are invulnerability for next 2 hits!\n";
                        Sleep(1300);
                    }
                    else{
                        cout << "\nYou missed your hit!\n";
                        Sleep(1300);
                    }
                }
            else{
                cout << "\nYou out of flasks or missed the button! Be careful!\n";
                Sleep(1300);
            }
            move_doneHealerBoss(name, Player, Enemy);
            cout << "Now enemy's turn\n";
            Sleep(1000);
            turn = 1;
            }
            else{
                if(!invicible){
                    Player.takeDamage(Enemy.m_damage);
                }
                else if(invicible && Player.m_invulnerability != 0){
                    cout << "\nYou took 0 damage!\n";
                    Sleep(1300);
                    Player.m_invulnerability--;
                }
                else if(invicible && Player.m_invulnerability == 0){
                    Player.takeDamage(Enemy.m_damage);
                    invicible = false;
                }
                move_doneHealerBoss(name, Player, Enemy);
                cout << "\nOuch! Enemy just attacked you!\n";
                cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                if(skill == 1 && Player.m_invulnerability == 2) cout << "You can become invulnerable by typing \"3\"!\n";
                else if(skill == 1 && Player.m_invulnerability == 1) cout << "You are invulnerable!\n";
                else if(skill == 1 && Player.m_invulnerability == 0) cout << "\nYou can no longer become invulnerable!\n";
                else if(skill == 2 && Player.m_reincarnation != 0) cout << "You have an extra life!\n";
                else if(skill == 2 && Player.m_reincarnation == 0) cout << "You have wasted your extra life!\n";
                boss_health = Enemy.m_health;
                boss_shield = Enemy.m_shield;
                Sleep(1000);
                turn = 0;
            }
        }

        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

bool game3_lvl_3(string name, Assassin Player, Boss Enemy, int turn, int upgrade, int skill)
{
    while(Player.m_health > 0 && Enemy.m_health > 0)
        {
            if(turn == 0){
                int a;
                cin >> a;
                if(a == 1){
                    if(QTE(3000)){
                        if(skill == 2){
                            Enemy.takeDamage(Player.m_damage);
                            Player.m_health += 10;
                        }
                        else{
                            Enemy.takeDamage(Player.m_damage);
                        }
                    }
                    else{
                        cout << "\nYou missed your hit!";
                        Sleep(1300);
                    }
                }
                else if(a == 2 && Player.m_doubledamage != 0){
                    Enemy.takeDamage(2 * Player.m_damage);
                    Player.m_doubledamage--;
                    cout << "\nYou just dealt double damage!\n";
                    Sleep(1300);

                }
                else if(skill == 3 && a == 3 && Player.m_reduction != 0){
                    Enemy.minus_armour(50);
                    Enemy.takeDamage(Player.m_damage);
                    Player.m_reduction--;
                    cout << "\nEnemy's armour has reduced to 0\n";
                }
                else{
                    cout << "\nYou can't do it now!\n";
                    Sleep(1300);
                }
                move_doneAssassinBoss(name, Player, Enemy);
                cout << "Now enemy's turn\n";
                Sleep(1000);
                turn = 1;
            }
            else{
                if(upgrade == 2){
                    if(!evade()){
                        Player.takeDamage(Enemy.m_damage);
                        cout << "\nOuch! Enemy just attacked you!\n";
                    }
                    else{
                        Player.takeDamage(0);
                        cout << "\nYou have dodged enemy's hit!\n";
                    }
                }
                else{
                    Player.takeDamage(Enemy.m_damage);
                    cout << "\nOuch! Enemy just attacked you!\n";
                }
            move_doneAssassinBoss(name, Player, Enemy);
            cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to deal double damage!\n";
            Sleep(1000);
            turn = 0;
            }
        }
        if(Enemy.m_health <= 0 && Player.m_health >= 1) return true;
        else return false;
}

int main()
{
    cout << "================================================= Greetings, traveler ==================================================" << endl;
    cout << "What's your name, traveler?\n";
    string name;
    cin >> name;
    cout << "Okay, " << name << ", it's time to start!\n";
    cout << "At first, you need to select the class which you will play.\n";
    cout << "1 - Warrior. Stats: 100 HP, 20 DMG, 50 ARM, 1 flask\n";
    cout << "2 - Healer. Stats: 100 HP, 20 DMG, 20 ARM, 4 flasks\n";
    cout << "3 - Assassin. Stats: 70 HP, 30 DMG, 10 ARM and opportunity to deal double damage\n";
    int number;
    cin >> number;
    if(number == 1)
    {
        Warrior Player;
        Player.setParameter(name, 100, 20, 50, 1);
        cout << "Good choice! Now let's begin our journey!\n";
        Sleep(1000);
        system("cls");

        Warrior Enemy;
        Enemy.setParameter("Enemy", 100, 20, 50, 1);

        move_doneWarrior(name, Player, Enemy);
        Sleep(1000);
        move_doneWarrior(name, Player, Enemy);
        cout << "\nYou spotted an enemy! Time to fight\n";
        cout << "\nAt first, you and the enemy have 1 flask that means that you can heal up 1 time\n";
        cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";

        int turn = 0;
        if(game1_lvl_1(name, Player, Enemy, turn)){
            system("cls");
            cout << "\nCongratulations! You just killed the enemy!\n";
            cout << "\nTime to claim your reward!\n";
            cout << "\n1 - Diamond sword. Increases your damage by 10\n2 - Shield. Increases your health by 15 and your armour by 25\n3 - Belt for flasks. Increases your maximum number of flasks by 2\n";
            int reward_1;
            cin >> reward_1;
            int &upgrade = reward_1;
            bool prize_taken = false;
            while(!prize_taken){
                if(upgrade == 1){
                    Player.setParameter(name, 100, 30, 50, 1);
                    prize_taken = true;
                }
                else if(upgrade == 2){
                    Player.setParameter(name, 115, 20, 75, 1);
                    prize_taken = true;
                }
                else if(upgrade == 3){
                    Player.setParameter(name, 100, 20, 50, 3);
                    prize_taken = true;
                }
                else{
                    cout << "\nPlease type correct number\n";
                }
            }
            cout << "Alright, " << name << ", let's continue our journey!\n";
            Sleep(1300);
            system("cls");
            cout << "Time to second level!\nAt this level there is something like QTE(Quick Time Event)\nYou will see the word and you need to type this words as fast as you can, so be ready!";
            Sleep(4500);
            Enemy.setParameter("Powerful Enemy", 150, 20, 50, 1);
            move_doneWarrior(name, Player, Enemy);
            cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
            turn = 0;
            if(game1_lvl_2(name, Player, Enemy, turn, upgrade)){
                system("cls");
                cout << "\nCongratulations! You just killed the enemy!\n";
                cout << "\nTime to claim your reward!\nAt this level you have to choose your special move! That's what we have right there:\n";
                cout << "\n1 - Assassin's Mark. Allows you to deal double damage 2 times\n2 - Mortal Strike. You have 10% to kill enemy with only one hit\n3 - Blessing of the goddess. All your stats(except flasks) are increased by 15\n";
                prize_taken = false;
                int reward_2;
                cin >> reward_2;
                int &skill = reward_2;
                while(!prize_taken){
                    if(skill == 1 && upgrade == 1){
                        Player.setParameter(name, 100, 30, 50, 1);
                        Player.m_DDflasks = 2;
                        prize_taken = true;
                    }
                    else if(skill == 1 && upgrade == 2){
                        Player.setParameter(name, 115, 20, 75, 1);
                        Player.m_DDflasks = 2;
                        prize_taken = true;
                    }
                     else if(skill == 1 && upgrade == 3){
                        Player.setParameter(name, 100, 20, 50, 3);
                        Player.m_DDflasks = 2;
                        prize_taken = true;
                    }
                    if(skill == 2 && upgrade == 1){
                        Player.setParameter(name, 100, 30, 50, 1);
                        prize_taken = true;
                    }
                    else if(skill == 2 && upgrade == 2){
                        Player.setParameter(name, 115, 20, 75, 1);
                        prize_taken = true;
                    }
                    else if(skill == 2 && upgrade == 3){
                        Player.setParameter(name, 100, 20, 50, 3);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 1){
                        Player.setParameter(name, 115, 45, 65, 1);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 2){
                        Player.setParameter(name, 130, 35, 90, 1);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 3){
                        Player.setParameter(name, 115, 35, 65, 3);
                        prize_taken = true;
                    }
                    else{
                        cout << "\nPlease type correct number\n";
                    }
                }
                cout << "Alright, " << name << ", let's continue our journey!\n";
                Sleep(1300);
                system("cls");
                cout << "You're almost there! Time to boss fight!";
                Sleep(1300);
                system("cls");
                Boss Enemy_Boss;
                Enemy_Boss.setParameter("Boss", 150, 20, 50, 50);
                cout << "Boss has a shield that absorbs damage! You need to destroy shield before you can kill him!";
                Sleep(1300);
                move_doneWarriorBoss(name, Player, Enemy_Boss);
                cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                turn = 0;
                if(game1_lvl_3(name, Player, Enemy_Boss, turn, upgrade, skill)){
                    system("cls");
                    cout << "\nCongratulations! You beat the game!\n";
                }
                else{
                    system("cls");
                    cout << "\nUnfortunately, you lost. Better luck next time!\n";
                }
            }
            else{
                system("cls");
                cout << "\nUnfortunately, you lost. Better luck next time!\n";}
        }
        else{
            system("cls");
            cout << "\nUnfortunately, you lost. Better luck next time!\n";}

    }
    else if(number == 2)
    {
        Healer Player;
        Player.setParameter(name, 100, 20, 20, 4);
        cout << "Good choice! Now let's begin our journey!\n";
        Sleep(1000);
        system("cls");

        Warrior Enemy;
        Enemy.setParameter("Enemy", 100, 20, 50, 1);

        move_doneHealear(name, Player, Enemy);
        Sleep(1000);
        move_doneHealear(name, Player, Enemy);
        cout << "\nYou spotted an enemy! Time to fight\n";
        cout << "\nAt first, you and the enemy have 4 flask that means that you can heal up 4 times\n";
        cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";

        int turn = 0;
        if(game2_lvl_1(name, Player, Enemy, turn)){
            system("cls");
            cout << "\nCongratulations! You just killed the enemy!\n";
            cout << "\nTime to take your reward!\n";
            cout << "\n1 - Magic Stick. Increases your damage by 10\n2 - Mantle of Intelligence. Increases your armour by 50\n3 - Vitality booster. Increases heal from your flasks(50 instead of 25)\n";
            int reward_1;
            int hp_heal = 25;
            cin >> reward_1;
            int &upgrade = reward_1;
            bool prize_taken = false;
            while(!prize_taken){
                if(upgrade == 1){
                    Player.setParameter(name, 100, 30, 20, 4);
                    prize_taken = true;
                }
                else if(upgrade == 2){
                    Player.setParameter(name, 100, 20, 70, 4);
                    prize_taken = true;
                }
                else if(upgrade == 3){
                    Player.setParameter(name, 100, 20, 20, 4);
                    hp_heal = 50;
                    prize_taken = true;
                }
                else{
                    cout << "\nPlease type correct number\n";
                }
            }
            cout << "Alright, " << name << ", let's continue our journey!\n";
            Sleep(1300);
            system("cls");
            cout << "Time to second level!\nAt this level there is something like QTE(Quick Time Event)\nYou will see the word and you need to type this words as fast as you can, so be ready!";
            Sleep(4500);
            Enemy.setParameter("Powerful Enemy", 150, 20, 50, 1);
            move_doneHealear(name, Player, Enemy);
            cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
            turn = 0;
            if(game2_lvl_2(name, Player, Enemy, turn, upgrade, hp_heal)){
                system("cls");
                cout << "\nCongratulations! You just killed the enemy!\n";
                cout << "\nTime to claim your reward!\nAt this level you have to choose your special move! That's what we have right there:\n";
                cout << "\n1 - Invulnerability. You take no damage from enemy hits 2 times\n2 - Reincarnation. When your HP has dropped below 0 you are reborn with a damage penalty\n3 - Blessing of the goddess. All your stats(except flasks) are increased by 15\n";
                bool prize_taken2 = false;
                int reward_2;
                cin >> reward_2;
                int &skill = reward_2;
                while(!prize_taken2){
                    if(skill == 1 && upgrade == 1){
                        Player.setParameter(name, 100, 30, 20, 4);
                        Player.m_invulnerability = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 1 && upgrade == 2){
                        Player.setParameter(name, 100, 20, 70, 4);
                        Player.m_invulnerability = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 1 && upgrade == 3){
                        Player.setParameter(name, 100, 20, 20, 4);
                        Player.m_invulnerability = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 2 && upgrade == 1){
                        Player.setParameter(name, 100, 30, 20, 4);
                        Player.m_reincarnation = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 2 && upgrade == 2){
                        Player.setParameter(name, 100, 20, 70, 4);
                        Player.m_reincarnation = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 2 && upgrade == 3){
                        Player.setParameter(name, 100, 20, 20, 4);
                        Player.m_reincarnation = 1;
                        prize_taken2 = true;
                    }
                    else if(skill == 3 && upgrade == 1){
                        Player.setParameter(name, 115, 45, 35, 4);
                        prize_taken2 = true;
                    }
                    else if(skill == 3 && upgrade == 2){
                        Player.setParameter(name, 115, 35, 85, 4);
                        prize_taken2 = true;
                    }
                    else if(skill == 3 && upgrade == 3){
                        Player.setParameter(name, 115, 35, 35, 4);
                        prize_taken2 = true;
                    }
                    else{
                        cout << "\nPlease type correct number\n";
                    }
                }
                cout << "Alright, " << name << ", let's continue our journey!\n";
                Sleep(1300);
                system("cls");
                cout << "You're almost there! Time to boss fight!";
                Sleep(1300);
                system("cls");
                Boss Enemy_Boss;
                Enemy_Boss.setParameter("Boss", 150, 20, 50, 50);
                cout << "Boss has a shield that absorbs damage! You need to destroy shield before you can kill him!";
                Sleep(1300);
                move_doneHealerBoss(name, Player, Enemy_Boss);
                cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                turn = 0;
                bool invicible = false;
                if(game2_lvl_3(name, Player, Enemy_Boss, turn, upgrade, skill, hp_heal, invicible)){
                    system("cls");
                    cout << "\nCongratulations! You beat the game!\n";
                }
                else if(Player.m_reincarnation == 1){
                    system("cls");
                    cout << "Arthas moment\nTry harder this time!\n";
                    Sleep(1300);
                    if(upgrade == 1) Player.setParameter(name, 100, 25, 20, 4);
                    else if(upgrade == 2) Player.setParameter(name, 100, 15, 70, 4);
                    else if(upgrade == 3) Player.setParameter(name, 100, 15, 20, 4);
                    Player.m_reincarnation--;
                    Enemy_Boss.setParameter("Boss", boss_health, 20, 50, boss_shield);
                    move_doneHealerBoss(name, Player, Enemy_Boss);
                    cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                    turn = 0;
                    if(game2_lvl_3(name, Player, Enemy_Boss, turn, upgrade, skill, hp_heal, invicible)){
                        system("cls");
                        cout << "\nCongratulations! You beat the game!\n";
                    }
                    else{
                        system("cls");
                        cout << "\nUnfortunately, you lost. Better luck next time!\n";
                    }
                }
                else{
                    system("cls");
                    cout << "\nUnfortunately, you lost. Better luck next time!\n";
                }
            }
            else{
                system("cls");
                cout << "\nUnfortunately, you lost. Better luck next time!\n";}
        }
        else{
            system("cls");
            cout << "\nUnfortunately, you lost. Better luck next time!\n";}
    }
    else if(number == 3)
    {
        Assassin Player;
        Player.setParameter(name, 70, 30, 10, 1);
        cout << "Good choice! Now let's begin our journey!\n";
        Sleep(1000);
        system("cls");

        Warrior Enemy;
        Enemy.setParameter("Enemy", 100, 20, 50, 2);

        move_doneAssassin(name, Player, Enemy);
        Sleep(1000);
        move_doneAssassin(name, Player, Enemy);
        cout << "\nYou spotted an enemy! Time to fight\n";
        cout << "\nAt first, you can hit the enemy with x2 damage only 1 time\n";
        cout << "\nTime to make your move! Type \"1\" if you want to attack or type \"2\" if you want attack with double damage\n";

        int turn = 0;
        if(game3_lvl_1(name, Player, Enemy, turn)){
            system("cls");
            cout << "\nCongratulations! You just killed the enemy!\n";
            cout << "\nTime to take your reward!\n";
            cout << "\n1 - Life Amulet. Increases your HP by 40\n2 - Trickster Cloak. Grants you 20 evasion rating(1 evasion = 1% to dodge hit)\n3 - Ring of Tailwind. You can deal double damage twice\n";
            int reward_1;
            cin >> reward_1;
            int &upgrade = reward_1;
            bool prize_taken = false;
            while(!prize_taken){
                if(upgrade == 1){
                    Player.setParameter(name, 110, 30, 10, 1);
                    prize_taken = true;
                }
                else if(upgrade == 2){
                    Player.setParameter(name, 70, 30, 10, 1);
                    Player.m_evasion = 20;
                    prize_taken = true;
                }
                else if(upgrade == 3){
                    Player.setParameter(name, 70, 30, 10, 2);
                    prize_taken = true;
                }
                else{
                    cout << "\nPlease type correct number\n";
                }
            }
            cout << "Alright, " << name << ", let's continue our journey!\n";
            Sleep(1300);
            system("cls");
            cout << "Time to second level!\nAt this level there is something like QTE(Quick Time Event)\nYou will see the word and you need to type this words as fast as you can, so be ready!";
            Sleep(4500);
            Enemy.setParameter("Powerful Enemy", 150, 20, 50, 1);
            move_doneAssassin(name, Player, Enemy);
            cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
            turn = 0;
            if(game3_lvl_2(name, Player, Enemy, turn, upgrade)){
                system("cls");
                cout << "\nCongratulations! You just killed the enemy!\n";
                cout << "\nTime to claim your reward!\nAt this level you have to choose your special move! That's what we have right there:\n";
                cout << "\n1 - Corrosive Haze. You can reduce enemy armour\n2 - Vampiric Aura. Each your hit heals you by 10 HP\n3 - Blessing of the goddess. All your stats(except flasks) are increased by 15\n";
                prize_taken = false;
                int reward_2;
                cin >> reward_2;
                int &skill = reward_2;
                while(!prize_taken){
                    if(skill == 1 && upgrade == 1){
                        Player.setParameter(name, 110, 30, 10, 1);
                        Player.m_reduction = 1;
                        prize_taken = true;
                    }
                    else if(skill == 1 && upgrade == 2){
                        Player.setParameter(name, 70, 30, 10, 1);
                        Player.m_reduction = 1;
                        prize_taken = true;
                    }
                     else if(skill == 1 && upgrade == 3){
                        Player.setParameter(name, 70, 30, 10, 2);
                        Player.m_reduction = 1;
                        prize_taken = true;
                    }
                    if(skill == 2 && upgrade == 1){
                        Player.setParameter(name, 110, 30, 10, 1);
                        prize_taken = true;
                    }
                    else if(skill == 2 && upgrade == 2){
                        Player.setParameter(name, 70, 30, 10, 1);
                        prize_taken = true;
                    }
                    else if(skill == 2 && upgrade == 3){
                        Player.setParameter(name, 70, 30, 10, 1);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 1){
                        Player.setParameter(name, 125, 45, 25, 1);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 2){
                        Player.setParameter(name, 85, 45, 25, 1);
                        prize_taken = true;
                    }
                    else if(skill == 3 && upgrade == 3){
                        Player.setParameter(name, 85, 45, 25, 2);
                        prize_taken = true;
                    }
                    else{
                        cout << "\nPlease type correct number\n";
                    }
                }
                cout << "Alright, " << name << ", let's continue our journey!\n";
                Sleep(1300);
                system("cls");
                cout << "You're almost there! Time to boss fight!";
                Sleep(1300);
                system("cls");
                Boss Enemy_Boss;
                Enemy_Boss.setParameter("Boss", 150, 20, 50, 50);
                cout << "Boss has a shield that absorbs damage! You need to destroy shield before you can kill him!";
                Sleep(1300);
                move_doneAssassinBoss(name, Player, Enemy_Boss);
                cout << "\nYour move! Show your best! Type \"1\" if you want to attack or type \"2\" if you want to heal\n";
                turn = 0;
                if(game3_lvl_3(name, Player, Enemy_Boss, turn, upgrade, skill)){
                    system("cls");
                    cout << "\nCongratulations! You beat the game!\n";
                }
                else{
                    system("cls");
                    cout << "\nUnfortunately, you lost. Better luck next time!\n";
                }
            }
            else{
                system("cls");
                cout << "\nUnfortunately, you lost. Better luck next time!\n";
            }
        }
        else{
            system("cls");
            cout << "\nUnfortunately, you lost. Better luck next time!\n";}
    }
    else if (number > 3)
    {
        system("cls");
        cout << "You selected the wrong class! Restart and make a right choice!";
    }
}
