#include <QString>
#include <QMap>



QString outString;
const QMap <QChar, QString> morseCode ={
                                    {' ', " "},
                                    {'a', ".___"},
                                    {'b', "_..."},
                                    {'c',"___.___."},
                                    {'d',"___.."},
                                    {'e', "."},
                                    {'f', "..___."},
                                    {'g', "______."},
                                    {'h', "...."},
                                    {'i', ".."},
                                    {'j', "._________"},
                                    {'k', "___.___"},
                                    {'l', ".___.."},
                                    {'m', "______"},
                                    {'n', "___."},
                                    {'o', "_________"},
                                    {'p', ".______."},
                                    {'q', "______.___"},
                                    {'r', ".___."},
                                    {'s', "..."},
                                    {'t', "_"},
                                    {'u', "..___"},
                                    {'v', "...___"},
                                    {'w', ".______"},
                                    {'x', "___..___"},
                                    {'y', "___.______"},
                                    {'z', "______.."},
                                    {'1', ".____________"},
                                    {'2', ".._________"},
                                    {'3', "...______"},
                                    {'4', "....___"},
                                    {'5', "....."},
                                    {'6', "___...."},
                                    {'7', "______..."},
                                    {'8', "_________.."},
                                    {'9', "____________."},
                                    {'0', "_______________"},
                                    {'.',"......"},
                                    {',',"._._._"},
                                    {';',"_._._."},
                                    {':',"___..."},
                                    {'?',"..__.."},
                                    {'!',"__..__"},
                                    {'-',"_...._"},
                                    {'`',".____."}
                                };


inline QString& translate(const QString &inpStr, const bool &isMorse)
 {
     outString.clear();
     auto inpItr = inpStr.begin();
     auto inpEnd = inpStr.end();

     if (isMorse)
     {
         QString letter;    //временная буква в представлении азбуки
         while(inpItr!=inpEnd)
         {
             if(*inpItr!=' ')  //если символ не равен пробелу, то формируем букву в представлении азбуки
             {
                 letter+=*inpItr;
             }
             else
             {
                 if(!letter.isEmpty())    //если есть представление буквы, то переводим её из азбуки Морзе и очищаем представление
                 {
                     auto morseItr = morseCode.begin();
                     auto morseEnd = morseCode.end();
                     while(morseItr!=morseEnd)
                     {
                         if(letter == morseItr.value())
                         {
                             outString+=morseItr.key();
                             letter.clear();
                             break;
                         }
                         ++morseItr;
                     }
                 }
                 else
                 {
                     outString+=morseCode.begin().key(); //иначе ставим пробел для разделениея слов
                 }
             }
             ++inpItr;
         }
         return outString;
     }
     else
     {
         while(inpItr!=inpEnd)
         {
             if (*inpItr!=' ')
             {
                 auto morseItr = morseCode.begin();
                 auto morseEnd = morseCode.end();
                 while(morseItr!=morseEnd)
                 {
                     if(inpItr->toLower()==morseItr.key()) //если символ из исходной строки совпадает с определением из азбуки, то записываем букву в формате морзе с добавлением пробела
                     {
                         outString+= morseItr.value() + morseCode.begin().value();
                         break;
                     }
                     ++morseItr;
                 }
             }
             else
             {
                 outString+=morseCode.begin().value();
             }
             ++inpItr;
         }
         return outString;
     }
 }
