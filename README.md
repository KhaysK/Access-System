
# Room Access System

<hr>
<h3>About project:</h3>
This project is an implementation of access system in the Unnopolis University. The data base of the program consist of:
<br>
<br>
<b> 5 user types </b>
<li>Admin</li>
<pre>
    2 admins available :
       password of the first: "123456789qwerty"
       password of the second: "dagestan1332"
</pre>
<li>Director</li>
<pre>
    1 director available :
       Tormasov Alexandr Gennadievich
</pre>
<li>Professor</li>
<pre>
    4 professors available :
       Zuev Eugeni Mikhailovich
       Manuel Mazzara
</pre>
<li>Lab employee</li>
<pre>
    8 professors available :
       Kholmatova Zamira Karimovna
       Ergasheva Shokhista Muradovna
</pre>
<li>Student</li>
<pre>
    16 professors available :
       Khaysadykov Khabib Jamaludinovich
       Khalilov Vagif Ruslanovich
</pre>
<li>Guests</li>
<pre>
    3 guests available :
       John Conor
       Kirilin Anton Egorovich
       Akhmetov Burbo Alievich
</pre>
<i>P.S. abow was mentioned some user for checking program, more user you can find in "region Creating_users" - line 170</i>
<br>
<br>
<b> 5 access levels </b>
<li>Red</li>
<li>Yellow</li>
<li>Green</li>
<li>No_Level</li>
<li>Blue</li>
<br>
<b> 21 rooms </b>

<table>  
<tr><th>Conferense on 1th floor</th><th>Class room</th><th>Lecture halls</th><th>Conferense room</th><th>Personal cabinets</th></tr>  
<tr><td>101</td><td>312</td><td>105</td><td>404</td><td>400</td></tr>  
<tr><td>102</td><td>313</td><td>106</td><td>405</td><td>401</td></tr>  
<tr><td>103</td><td>314</td><td>107</td><td>406</td><td>402</td></tr>  
<tr><td>-</td><td>317</td><td>108</td><td>407</td><td>403</td></tr>  
<tr><td>-</td><td>-</td><td>-</td><td>-</td><td>408</td></tr>  
<tr><td>-</td><td>-</td><td>-</td><td>-</td><td>409</td></tr>  
</table>  
<br>
Programm by itself is a terminal program where available 2 options: user menu and admin menu
<br>
<br>
In user menu firstly information about user printed,
then user can choose actions:

```bash
Open room
Exit
Close program
```
In admin menu firstly information about admin printed,
then admin can choose actions:
```bash
Add new user
Set level to user
Set room to user
Exit
Emergency situation
Emergency situation is over
Close program
```
<br>
<h5>Remark:</h5>
Program recognized name of user in such format <i>Surname Name Patronymic</i> starting with capital letter,
it also will take name, surname and partonymic in different order but for accuracy it would be better follow given format
<br>

For example:
<br>

"Khaysadykov Khabib Jamaludinovich" - good name
<br>
"Khabib Khaysadykov Jamaludinovich" - bad name (<i>but will work</i>)
<br>
"khaysadykov khabib jamaludinovich" - very bad name
<hr>

<h3>Dependencies:</h3>
<li>GNU Make minimum (VERSION 3.17) </li>
<li>clang (Version 6.0.0)</li>
<li>IDE Clion</li>

<hr>

<h3>Building:</h3>

To build the project, use the following command in bash terminal:

```bash
cd <source path of Project>
gcc main.cpp -o accessSystem
```

