#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

  int monsterfight(string , int , int) ; //Prototype for monster battle
  int finalbossfight(string , int , int ) ; //Prototype for final boss battle
  void fightwinloseoutput(int, int) ; //Prototype for w/l output and exp given

  //Declaration and Initialization of Global variables to manage hero stats
  int herolevel = 1 ;
  int herostr = 1 + herolevel ;
  int herodef = 1 + herolevel ;
  int herohp = 10 + herolevel ;
  int heroexpcount = 0 ;
  string heroname ; //User input hero name

  //Total monsters defeated for end game stat
  int monstersdefeated = 0 ;

int main () 
{
  int cavetripchecker = 0 ; //Checks if user is at first boss attempt (0), then plays intro text
  int winlosestate = 0 ; //Variable to track whether a battle is win or lose (1=win 0=lose)
  int bossdefeatstate = 0 ; // Allows exit from loop if final boss is defeated (1), then brings user to ending

  //Declare and Initialize variables to keep track of monster stats, exp given, and monster name
  int monsterhp = 0 ;
  int monsterattack = 0 ;
  int monsterexpgiven = 0 ;
  string monster;

  int herolocation = 0 ; //Declare and Initialize variable for user input location


  // Intro text, user inputs their name
  cout << "Welcome to our tavern weary wanderer! Sit down, have a drink! Please, tell us yer name!" << endl << endl ;
  cout << "My name is: " ;
  cin >> heroname ;
  cout << endl << "Ahh, hello there " << heroname << "! Allow me to thank you for assisting in the cleanup of monsters round our town. I shall give ye directions to each of the locations in and around our town." << endl << endl << "Over at the church there, ye may restore your health to full. Out in the field, you can help us clear the monsters out to yer heart's content." << endl << endl << "Once you hit level 5 and feel ye are ready to clear out the source of these monsters,  come visit me again and I'll let ye know if I hear anything. " << endl << endl << "You depart the tavern." << endl << endl ;

  
  while(bossdefeatstate == 0) //Keeps player stuck in loop until final boss is defeated
  {
    cout << "It's time to head out! Where to? (Enter 1,2, or 3) " << endl << endl ;
    cout << "1. The Church" << endl << "2. The Field" << endl << "3. The Tavern (Must be at least level 5. Be sure you're ready for a tough fight!)" << endl << endl ;
    cin >> herolocation ; //Input for user to choose location

    while(herolocation > 3 || herolocation < 1 ) //User input validation to keep choice 1 through 3
    {
      cin.clear();
      cin.ignore(10000, '\n'); 
      cout << endl << "Yikes! I can't go there. I must choose from the church, the field, or the tavern." << endl ;
      cin >> herolocation ;
    }
    // if/else if statements for church (1), field(2), and tavern (3) of user input
    if(herolocation == 1) //Church
    {
      cout << endl << "You decide to head to the church. The head priest is on duty." << endl << endl ;
      cout << "Ahh, welcome " << heroname << ". I have heard much of your deeds. Please, allow me to place a blessing upon you." << endl << endl ;
      cout << "The head priest blesses you, and your health is restored to full!" << endl << endl << "You depart the church." << endl << endl ;
      herohp = 10 + herolevel ; //Sets user's hp back to max

    }
    else if(herolocation == 2) //Field
    {
      cout << "You decide to head to the field." << endl << endl << "Suddenly, a monster rushes toward you!" << endl << endl ;

      srand (time(NULL)); // Initializes random seed
      int whichmonster = rand() % 3 ; //Generates number 0 through 2 to determine which monster is fought

      if(whichmonster == 0)
      {
        //Sets monster name,stats, and exp given
        monster = "Slime" ;
        monsterattack = 3 ;
        monsterhp = 5 ;
        monsterexpgiven = 2 ;

        winlosestate = monsterfight(monster, monsterattack, monsterhp) ; // Battle state, returns win (1) or loss (0)
        fightwinloseoutput(winlosestate , monsterexpgiven) ; //Returns exp lost/gained
      }
      else if(whichmonster == 1)
      {
        //Sets monster name,stats, and exp given
        monster = "Robot" ;
        monsterattack = 3 ;
        monsterhp = 10 ;
        monsterexpgiven = 3 ;

        winlosestate = monsterfight(monster, monsterattack, monsterhp) ; // Battle state, returns win (1) or loss (0)
        fightwinloseoutput(winlosestate , monsterexpgiven) ; //Returns exp lost/gained

      }
      else if(whichmonster == 2)
      {
        //Sets monster name,stats, and exp given
        monster = "Sword-headed Rhino" ;
        monsterattack = 4 ;
        monsterhp = 7 ;
        monsterexpgiven = 4 ;

        winlosestate = monsterfight(monster, monsterattack, monsterhp) ; // Battle state, returns win (1) or loss (0)
        fightwinloseoutput(winlosestate , monsterexpgiven) ; //Returns exp lost/gained
      }
      if(heroexpcount >=25) //Check hero exp post-battle and readjust stats and level if exp >= 25
      {
        heroexpcount = 0 ;
        herolevel++ ;
        int herostr = 1 + herolevel ;
        int herodef = 1 + herolevel ;
        int herohp = 10 + herolevel ;
        cout << "Congratulations! You have leveled up to level " << herolevel << " !" << endl << endl << "Your strength is now: " << herostr << endl << endl << "Your defense is now: " << herodef << endl << endl << "Your hp is now: " << herohp << endl << endl ;

      }
    }
    else if (herolocation == 3) //Tavern
    {
      if(herolevel < 5) //Checks if user is requisite level for final boss
      {
        cout << endl << "I'm not yet ready to speak with the tavern keeper. I must be at least level 5 before I am ready for a challenge!" << endl << endl ;
      }
      else if(herolevel >= 5 && cavetripchecker == 0) //User's level is greater to or equal than 5, final boss begins
      {
        //Sets final boss name and stats
        monster = "Drachensoul" ;
        monsterattack = 8 ;
        monsterhp = 40 ;

        cavetripchecker = 1 ; // Switches to 1 to note user has taken first attempt at cave (Will play alternate text from now on)

        cout << endl << "You decide you're ready to end the source of the monsters and check in with the tavern keeper to see if he has heard anything." << endl << endl ;

        cout<< "OI! Fancy seeing you again here mate! Do I have some juicy news for you! " << endl << "After speaking with other adventurers that were not unlike yerself, it turns out there is a high concentration of monsters near the Cave of Eld. I might suggest you take a look there!" << endl << endl ;

        cout << "You depart the tavern and head for the Cave of Eld." << endl << endl ;

        cout << "You approach the interior of the dimly lit cavern. An amphorus figure lies ahead." << endl << endl ;

        cout << "I AM DRACHENSOUL, THE SOUL OF AN ELDER DRAGON SLAIN BY MAN! YOU DARE ENTER MY CAVE? SPEAK YOUR NAME!" << endl << endl ;

        cout << "My name is " << heroname << ", and I have come to end the source of these monsters! You are evil, and must be destroyed!" << endl << endl ;

        cout << "A FOOL'S NAME TO BE SURE. MAN HATH DARED TO SLAY ME IN LIFE, AND SO I HAVE BROUGHT ENDLESS MONSTERS AND SUFFERING UPON THIS WORLD. IT SEEMS MAN DOES NOT AGREE WITH THE VENGENCE I AM UNLEASHING FOR MY LIFE HAVING BEEN TAKEN SO MANY YEARS AGO, AND AS SUCH WISHES TO TAKE MY AFTERLIFE TOO. COME FORTH AND FACE YOUR FOE!" << endl << endl ;

        bossdefeatstate = finalbossfight(monster , monsterattack , monsterhp ) ;
      }
      else if(herolevel >= 5 && cavetripchecker == 1) //User's level is greater to or equal than 5 and second attempt or beyond for boss fight 
      {
        //Sets final boss name and stats
        monster = "Drachensoul" ;
        monsterattack = 8 ;
        monsterhp = 40 ;

        cout << endl << "OI! I hear about yer defeat friend. Don't give it too much thought! Get back out there and show 'em who's who!" << endl << endl ;

        cout << "You depart the tavern and head for the Cave of Eld." << endl << endl ;

        cout << "IT SEEMS YOU HATH NOT LEARNED YOUR LESSON FROM YOUR FIRST ATTEMPT. COME FORTH WITH YOUR BLADE IN HAND." << endl << endl;

        bossdefeatstate = finalbossfight(monster , monsterattack , monsterhp ) ;
      }
    }


  }

  //Final boss defeated, end game text and stats displayed
  cout << "Drachensoul begins to fade... the cave is crumbling!" << endl << endl ;
  cout << "With all your remaining might, you rush out of the cave and back to town. You hear noise coming from the town, as if there is trouble." << endl << endl ;
  cout << "You pass the town's front gate, and notice a crowd of adventurers and the tavernkeeper waiting for you." << endl << endl ;

  cout << "OI! We heard the news mate! Congratulations on bein the stuff of legends! No longer shall we be plagued with monsters! Ye are a certified hero, and we are throwing a celebration for 'ye!" << endl << endl ;

  cout << "Congratulations on your victory " << heroname << "! Here are your stats:" << endl ;
  cout << "Level: " << herolevel << endl << "Strength: " << herostr << endl << "Defense: " << herodef << endl << "HP: " << herohp << endl << "Monsters defeated: " << monstersdefeated ;

  return 0 ; //Ends game
}


/* The fightwinloseoutput function takes in an integer to check whether a fight was a win (1) or loss(0) and the exp given by a monster. If the fight is a win, the user's exp count is increased by the amount rewarded by a monster. If the fight is a loss, the user loses one exp point */
void fightwinloseoutput(int wlstate , int expgiven)
{
  if(wlstate == 0)
  {
    cout << "The monster deals a devestating blow! You pass out, and some other adventurers chance upon you. They carry you back to the church, where the head priest applies first aid. You feel as though you've possibly lost some experience (1 exp point) in the process." << endl << endl ;
    heroexpcount -= 1 ;
    herohp = 10 + herolevel ;
    if(heroexpcount < 0) //Disallows exp counts less than 0
    {
      heroexpcount = 0 ;
    }
  }
  else if(wlstate == 1)
  {
          cout << "You finish the monster off with a devestating blow! You depart back to town, feeling more experienced! " << "(+" << expgiven << " experience)" << endl << endl ;
          heroexpcount += expgiven ;
  }
}

//Takes in monster name, monster attack, and monster hp generated by main function. Additionally, utilizes hero's global variable stats. Hero is kept in a battle loop until monster hp or hero hp is less than or equal to 0.

int monsterfight(string monname, int monattack, int monhp)
{
  srand (time(NULL)); // Initializes random seed
  cout << "A wild " << monname << " appears!" << endl << endl ;
  int herobattlestate = 0 ; //Variable to check for user's attack/defend option
  int herodamagedealt = 0 ; //Variable to hold damage dealt by hero
  int monsterdamagedealt = 0 ; //Variable to hold damage dealt by monster
  int monsterstatebonus = 0 ; // Gives monster an attack or defense bonus based on stance
  int herostatebonus = 0 ; //Gives hero a defense bonus if defending
  int wlstate = 0 ; //Variable to hold battle won (1) or battle lost (0)

  while(monhp > 0 && herohp > 0)
  {
    
    int monsterbattlestate = rand() % 3 ; //Determines action monster will take and display

    if(monsterbattlestate == 0)
    {
      cout << "The " << monname << " takes up a normal stance!" ;
      monsterstatebonus = 0 ;
    }
    else if(monsterbattlestate == 1)
    {
      cout <<"The " << monname << " takes up a defensive stance!" ;
      monsterstatebonus = 2 ;
    }
    else if(monsterbattlestate == 2)
    {
      cout <<"The " << monname << " psyches itself up!" ;
      monsterstatebonus = 1 ;
    }

    cout << endl << endl << "It's your turn! what will you do?" << endl << endl ;
    cout << "1. Attack" << endl << endl << "2. Defend" << endl << endl ;
    cin >> herobattlestate ;

    while(herobattlestate != 1 && herobattlestate != 2) //User input validation loop
    {
      cin.clear();
      cin.ignore(10000, '\n'); 
      cout << "Yikes! I can only Attack (1) or Defend (2)! I will..." << endl << endl ;
      cin >> herobattlestate ; // Hero attacks (1) or defends (2)

    }


    if(herobattlestate == 1)
    {
      cout << endl << endl << "You slash at the " << monname << " !" ;
      herodamagedealt = herostr - monsterstatebonus ; //Calculates damage dealt and stores in variable
      monhp -= herodamagedealt ; //Lowers monsters hp by damage dealt

      if(monhp < 0) //Prevents display of negative monster hp
      {
        monhp = 0 ;
      }

      cout << endl << endl << "The " << monname << " takes " << herodamagedealt << " damage!" << endl << endl << monname << " HP: " << monhp << endl << endl ;
    }
    else if(herobattlestate == 2)
    {
      cout << endl << endl << "You take up a defensive stance!" << endl << endl ;
      herostatebonus = 1 ;
    }

    if(monsterbattlestate !=1 && monhp > 0) //Monster attacks if not defending this turn and is alive (monhp>0)
    {
      cout << endl << endl << "The " << monname << " attacks!" ;
      monsterdamagedealt = monattack + monsterstatebonus - herodef - herostatebonus ;

      if(monsterdamagedealt < 0) //Prevents monster damage less than 0
      {
        monsterdamagedealt = 0 ;
      }
      //Calculates monster damage dealt and stores in variable
      herohp -= monsterdamagedealt ; //Lowers hero hp by damage dealt
      cout << endl << endl << "You take " << monsterdamagedealt << " damage!" << endl << endl ;

      if(herohp < 0) //Prevents negative hp values to be displayed
      {
      herohp = 0 ;
      }

      cout << "Hero HP: " << herohp << endl << endl ;
    }

  }

  if(herohp <= 0) //Sets wlstate to 0 if hero loses (Hero hp 0)
  {
    wlstate = 0 ;
  }
  else if(monhp <= 0)//Sets wlstart 1 is hero wins (Monster hp 0)
  {
    wlstate = 1 ;
    monstersdefeated++ ;//Add 1 to number of monstersdefeated
  }
  
  return wlstate ;
}

//Takes in monster name, monster attack, and monster hp generated by main function. Additionally, utilizes hero's global variable stats. Hero is kept in a battle loop until boss hp or hero hp is less than or equal to 0.
int finalbossfight(string bossname , int bossattack , int bosshp )
{
  srand (time(NULL)); // Initializes random seed
  cout << bossname << " approaches!" << endl << endl ;
  int herobattlestate = 0 ; //Variable to check for user's attack/defend option
  int herodamagedealt = 0 ; //Variable to hold damage dealt by hero
  int bossdamagedealt = 0 ; //Variable to hold damage dealt by monster
  int bossstatebonus = 0 ; // Gives monster an attack or defense bonus based on stance
  int herostatebonus = 0 ; //Gives hero a defense bonus if defending
  int wlstate = 0 ; //Variable to hold battle won (1) or battle lost (0)

  while(bosshp > 0 && herohp > 0)
  {
    
    int bossbattlestate = rand() % 3 ; //Determines action monster will take and display

    if(bossbattlestate == 0)
    {
      cout << bossname << " looks fierce!" ;
      bossstatebonus = 0 ;
    }
    else if(bossbattlestate == 1)
    {
      cout << bossname << " takes the form of a dragonhide shield!" ;
      bossstatebonus = 5 ;
    }
    else if(bossbattlestate == 2)
    {
      cout << bossname << " is prepping a draconic blow!" ;
      bossstatebonus = 3 ;
    }

    cout << endl << endl << "It's your turn! what will you do?" << endl << endl ;
    cout << "1. Attack" << endl << endl << "2. Defend" << endl << endl ;
    cin >> herobattlestate ;

    while(herobattlestate != 1 && herobattlestate != 2) //User input validation loop
    {
      cin.clear();
      cin.ignore(10000, '\n'); 
      cout << "Yikes! I can only Attack (1) or Defend (2)! I will..." << endl << endl ;
      cin >> herobattlestate ; // Hero attacks (1) or defends (2)

    }


    if(herobattlestate == 1)
    {
      cout << endl << endl << "You slash at " << bossname << "!" ;
      herodamagedealt = herostr - bossstatebonus ; //Calculates damage dealt and stores in variable
      bosshp -= herodamagedealt ; //Lowers monsters hp by damage dealt

      if(bosshp < 0) //Prevents display of negative monster hp
      {
        bosshp = 0 ;
      }

      cout << endl << endl << bossname << " takes " << herodamagedealt << " damage!" << endl << endl << bossname << " HP: " << bosshp << endl << endl ;
    }
    else if(herobattlestate == 2)
    {
      cout << endl << endl << "You take up a defensive stance!" << endl << endl ;
      herostatebonus = 1 ;
    }

    if(bossbattlestate !=1 && bosshp > 0) //Monster attacks if not defending this turn and is alive (monhp>0)
    {
      cout << endl << endl << bossname << " attacks!" ;
      bossdamagedealt = bossattack + bossstatebonus - herodef - herostatebonus ;

      if(bossdamagedealt < 0) //Prevents damage below 0
      {
        bossdamagedealt = 0 ;
      }
      //Calculates monster damage dealt and stores in variable
      herohp -= bossdamagedealt ; //Lowers hero hp by damage dealt
      cout << endl << endl << "You take " << bossdamagedealt << " damage!" << endl << endl ;

      if(herohp < 0) //Prevents negative hp values to be displayed
      {
      herohp = 0 ;
      }

      cout << "Hero HP: " << herohp << endl << endl ;
    }

  }

  if(herohp <= 0) //Sets wlstate to 0 if hero loses (Hero hp 0)
  {
    cout << "The boss deals a devestating blow! You pass out, and some other adventurers chance upon you. They carry you back to the church, where the head priest applies first aid. You feel as though you've possibly lost some experience (1 exp point) in the process." << endl << endl ;
    heroexpcount -= 1 ;
    herohp = 10 + herolevel ;
    if(heroexpcount < 0) //Disallows exp counts less than 0
    {
      heroexpcount = 0 ;
    }
    wlstate = 0 ;
  }
  else if(bosshp <= 0)//Sets wlstart 1 is hero wins (Monster hp 0)
  {
    wlstate = 1 ;
    herohp = 10 + herolevel ; //Sets herohp back to max for end of game stats
    monstersdefeated++ ;//Add 1 to number of monstersdefeated
  }
  
  return wlstate ;

}