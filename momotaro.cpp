//==============================
// How to run
// $ g++ -std=c++11 momotaro.cpp && ./a.out ; echo $?
#include <stdio.h>

//-----------------
// 役づくり
class 宝役{
};

class 鬼役{
    宝役* 宝 = NULL;
public:
    auto 宝を持つ(宝役* 宝)                     -> void{
        this->宝 = 宝;
    }
    auto やられる()                             -> 宝役*{
                                                printf("%s が %s\n", "鬼", __func__);
        宝役* 宝 = this->宝;
        this->宝 = NULL;
                                                printf("%s が出る\n", "宝");
        return 宝;
    }
};

class イヌ役{
};

class サル役{
};

class キジ役{
};

class 桃太郎役{
    宝役*   宝   = NULL;
    イヌ役* イヌ = NULL;
    サル役* サル = NULL;
    キジ役* キジ = NULL;
public:
    auto 仲間を得る(イヌ役* イヌ)               -> void{
                                                printf("%s が %s\n", "桃太郎", __func__);
        this->イヌ = イヌ;
    }
    auto 仲間を得る(サル役* サル)               -> void{
                                                printf("%s が %s\n", "桃太郎", __func__);
        this->サル = サル;
    }
    auto 仲間を得る(キジ役* キジ)               -> void{
                                                printf("%s が %s\n", "桃太郎", __func__);
        this->キジ = キジ;
    }
    auto 退治する(鬼役* 鬼)                     -> 宝役*{
                                                printf("%s が %s\n", "桃太郎", __func__);
        if(this->イヌ && this->キジ && this->サル){
            return 鬼->やられる();
        }else{
            return NULL;
        }
    }
    auto 宝を得る(宝役* 宝)                     -> void{
                                                printf("%s が %s\n", "桃太郎", __func__);
        this->宝 = 宝;
    }
	auto 残念がる()                             -> void{
                                                printf("%s が %s\n", "桃太郎", __func__);
	}
};

class 桃役{
    桃太郎役* 桃太郎 = NULL;
public:
    auto 桃太郎を格納する(桃太郎役* 桃太郎)     -> void{
        this->桃太郎 = 桃太郎;
    }
    auto 割れる()                               -> 桃太郎役*{
                                                printf("%s が %s\n", "桃", __func__);
        桃太郎役* 桃太郎 = this->桃太郎;
        this->桃太郎 = NULL;
                                                printf("%s が出る\n", "桃太郎");
        return 桃太郎;
    }
};

namespace 配役{
//private
    桃太郎役 山田;
    桃役     加藤;
    イヌ役   山内;
    サル役   中村;
    キジ役   木下;
    宝役     鈴木;
    鬼役     田中;
//public
    auto 桃登場()                               -> 桃役*{
                                                printf("%s\n", __func__);
        加藤.桃太郎を格納する(&山田);
        return &加藤;
    }
    auto 鬼登場()                               -> 鬼役*{
                                                printf("%s\n", __func__);
        田中.宝を持つ(&鈴木);
        return &田中;
    }
    auto イヌ登場()                             -> イヌ役*{
                                                printf("%s\n", __func__);
        return &山内;
    }
    auto サル登場()                             -> サル役*{
                                                printf("%s\n", __func__);
        return &中村;
    }
    auto キジ登場()                             -> キジ役*{
                                                printf("%s\n", __func__);
        return &木下;
    }
}



//-----------------
// おはなし
int main(){
        桃役* 桃     = 配役::桃登場();
    桃太郎役* 桃太郎 = 桃->割れる();
      イヌ役* イヌ   = 配役::イヌ登場();
                       桃太郎->仲間を得る(イヌ);
      サル役* サル   = 配役::サル登場();
                       桃太郎->仲間を得る(サル);
      キジ役* キジ   = 配役::キジ登場();
                       桃太郎->仲間を得る(キジ);
        鬼役* 鬼     = 配役::鬼登場();
        宝役* 宝     = 桃太郎->退治する(鬼);
                       if(宝) 桃太郎->宝を得る(宝);
                       else   桃太郎->残念がる();
              return ! 宝;
}


