/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:06:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-22 20:31:06
 * @FilePath: \mysticism-mud\World\base\Card\01\paper_replace.c
 * @Description:  纸人替身牌
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <ansi.h>
#include <mxp.h>
inherit _MXP;

public void init_mxp() {
    string s = @KNOW
    <!-- Elements to support the Automapper --><!ELEMENT RName '<FONT COLOR=Red><B>' FLAG="RoomName"><!ELEMENT RDesc FLAG='RoomDesc'><!ELEMENT RExits '<FONT COLOR=Blue>' FLAG='RoomExit'><!-- The next element is used to define a room exit link that sendsthe exit direction to the MUD if the user clicks on it --><!ELEMENT Ex '<SEND>'><!ELEMENT Chat '<FONT COLOR=Gray>' OPEN><!ELEMENT Gossip '<FONT COLOR=Cyan>' OPEN><!-- in addition to standard HTML Color specifications, you can use color attribute names such as blink --><!ELEMENT ImmChan '<FONT COLOR=Red,Blink>'><!ELEMENT Auction '<FONT COLOR=Purple>' OPEN><!ELEMENT Group '<FONT COLOR=Blue>' OPEN><!-- the next elements deal with the MUD prompt --><!ELEMENT Prompt FLAG="Prompt"><!ELEMENT Hp FLAG="Set hp"><!ELEMENT MaxHp FLAG="Set maxhp"><!ELEMENT Mana FLAG="Set mana"><!ELEMENT MaxMana FLAG="Set maxmana"><!-- now the MUD text -->
    <RName>The Main Temple</RName>
    <RDesc>This is the main hall of the MUD where everyone starts.
    Marble arches lead south into the town, and there is a <i>lovely</i>
    <send "drink &text;">fountain</send> in the center of the temple,</RDesc><RExits>Exits: <Ex>N</Ex>, <Ex>S</Ex>, <Ex>E</Ex>, <Ex>W</Ex></RExits>
    
    <Prompt>[<Hp>100</Hp>/<MaxHp>120</MaxHp>hp <Mana>50</Mana>/<MaxMana>55</MaxMana>mana]</Prompt>
KNOW;
    write("MXP test \n");
    //efun::write(process_mxp(MXPTAG("!ELEMENT RName '<FONT COLOR=Red><B>' FLAG=RoomName"), QueryMXP()));
    efun::write(process_mxp(MXPTAG(s), QueryMXP()));
    efun::write(process_mxp(MXPTAG("<VERSION>"), QueryMXP()));
    efun::write(process_mxp(MXPTAG("<SUPPORT>"), QueryMXP()));
}

