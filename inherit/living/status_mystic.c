//存储非凡状态对象
nosave protected object * living_mystic = ({0,0,0,0,0,0,0,0,0,0,0});
//存储非凡状态编号
//非凡途径编号*10 + 等级编号
protected int * mystic = ({0,0,0,0,0,0,0,0,0,0});

//rank 0-9 代表序列0-9， 10表示非序列途径加成
void add_mystic(object mys,int rank)
{
    living_mystic[rank] = mys ;
}

void update_mystic()
{
    for(int i=10;i--;i>=0)
    {
        if(living_mystic[rank] !=0)
        {
            living_mystic[rank]->change_value(this_object());
        }
    }
}