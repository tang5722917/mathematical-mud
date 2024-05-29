#ifndef MACHINE_H
#define MACHINE_H

object new_state(mapping state){
    object ob =  new(_STATE);
    if(ob->state_build(state))
        return ob;
    else return 0;
}

#endif
