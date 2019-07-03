
## BATTLESHIPZ FLOWERZ
###### {matrix based, agent driven navelgamez, with flowerz.noize.}


#### FOUND ORIGINAL OUTLINE AT:
###### https://stackoverflow.com/questions/56589644/adding-input-from-user-to-a-array-and-displaying-it
##### post by:marc_s

### OGINZ_;
found somone marc_s on stackoverflow makeing alittle game they had a few functions and a bunch of global vars but sitin in some main. it basicly did not do much. and was  more of a outline  ... i decided to make redo almost all of it, into a c++ class system, and  make it work.and make a proper little game, this is not done, i;ll likely work on it more as i feel like it kinda fun to build alittle bits from random somthing found.

i produced a game game board class, and add in ships classes, and a factory settup, and started to devlope the computer compoente setup expanded to a number of compoents, and layers of information restriction and passage to build up telemitary.. and design..

complie with {will be making a make file soon}

new complie line: g++ -std=c++17 main_ship.cpp ships.cpp ship_factory.cpp game_borad.cpp agent_act.cpp agent_sensor_memorx.cpp -o ship_out


### intent:
to have a base systemt o test out engine design that focus on algorithmic strutires, and code which is fully apart of the world building, and design philsiophy of the spaces manfest in the milieu.

### major reivisons:
so alot of the work is been broken int compotents, and folded simple class structires, diffrent ,
manfestions pass though stablity on move orders, and genreal scan on the system chars seems to work.
najor changes is allowing for the clauctive flow, to inage with the lanauge in a way thet can help open,
albale chanlles of attempt.

#### currentbuildpjkz:
basic facotry stucs, are working, feel confentd, to soon be able to brign them into the gride clacaions
lazzly i need to work on alot of the math and some of the calcutpory repsotoriez pre calced it seems
i think though should be able to make cycles, that only do it, every frew whavers, but, feel real. uint_id_maphowelse
to wez. ahez. anz.. i;ve been really pushign thre memoery struz. but, idk think ineed sti down and re code, alot of the models UML. and see how i can make sour ethis dance works well. otherise. been adding comments to clearup still alot more to be done.



#### current work
->make the agents be able to hang in the the playspace, and being anyaltics of their processing, diffrent sorce objects
for data around there world. and building up the interaction systems. and collition tetections, othe physics compoents,
and then make sure user interacion is respfulz.
but ya, clena up the flow from main to borad to etc. make sure what is soild is also fuid, and then do the work on the hellper funciosnz. agent problems may require a redeicdes, but at this poiint seem refsucise rethought and press be good, acurate and aprt.

OLD::now building in a msg system to and working on agent compoents to make the AI.... will see.
move had been disabled. but expanding the agent funcions..currntly msg systme offline..etc.

#### OTHER: FUTURE PLANz
id like to add a tilemap and mabye then a UDP connection system.

#### complie with {will be making a make file soon}

new complie line: g++ -std=c++17 main_ship.cpp ships.cpp ship_factory.cpp game_borad.cpp agent_act.cpp agent_sensor_memorx.cpp -o ship_out



old:
 g++ -std=c++17 main_ship.cpp ships.cpp ship_factory.cpp game_borad.cpp  -o ship_out
