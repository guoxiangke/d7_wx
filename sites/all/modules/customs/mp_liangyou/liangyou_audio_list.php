<?php

function liangyou_audio_list_bytitle(){
	$audios = liangyou_audio_list2();
	foreach ($audios as $code => $audio) {
    $audios[$code]['code'] = $code;
		$audios[$audio['title']] = $audios[$code];
		unset($audios[$code]);
	}
	return $audios;
}

function liangyou_audio_list_byindex(){
  $audios = liangyou_audio_list2();
  foreach ($audios as $code => $audio) {
    $audios[$code]['code'] = $code;
    $audios[$audio['index']] = $audios[$code];
    unset($audios[$code]);
  }
  return $audios;
}

function liangyou_audio_list_bylywxindex(){
  $audios = liangyou_audio_list2();
  foreach ($audios as $code => $audio) {
    $audios[$code]['code'] = $code;
    $audios[$audio['lywx']] = $audios[$code];
    unset($audios[$code]);
  }
  return $audios;
}
// $liangyou_audio_list2 = liangyou_audio_list2();
// foreach ($liangyou_audio_list2 as $key => $value) {
//   dpm('【'.$value['index'].'】'.$value['title'].($value['bce']?'♪':'' ));
// }
function liangyou_audio_list2(){
    return  array(
    'ib'=>array(
      'title' =>'无限飞行号',
      'day'=>'17',//17=>1-7 15=>1-5 67=>weekend 7=>7 6=>6 135=>135
      'index'=>601,
      'lywx'=>202,
      'category'=>'关怀辅导',
      'desc'=>'在这里，有与你遭遇相连的他和她；在这里，有渴望关心残疾人的你和我；在这里，有神与我们同飞行。突破身体心灵缺陷，发掘生命蕴藏的更美本质，一起登上属于你和我的《无限飞行号》',
      ),
    'im'=>array(
      'title' =>'i关怀心磁场',
      'day'=>'74',
      'index'=>602,//74 周五周六无,
      'lywx'=>203,
      'category'=>'关怀辅导',
      'desc'=>'人是身心灵的集合体，由外而内，我们看到光鲜亮丽背后的破碎；由内向外，我们看到伤心流泪后的希望',
      ),
    'cc'=>array(
      'title' =>'空中辅导',
      'day'=>'17',
      'index'=>603,
      'desc'=>'聆听听众各类苦闷心声，以圣经和祷告回应。在对话过程中，表达体会和盼望，指引成长的方向',
      'lywx'=>201,
      'category'=>'关怀辅导',
      ),
    'se'=>array(
      'title' =>'恋爱季节',
      'day'=>'15',
      'index'=>604,
      'lywx'=>301,
      'category'=>'婚恋家庭',
      'desc'=>'有人说：“最完美的爱情在小说里，最完美的婚姻在梦境里！”难道希望拥有完美的恋爱、婚姻，只是一个梦想吗？请立刻收听《恋爱季节》，梦想就要成真！欢迎孤男寡女、一男一女、已婚男女、不分男女，一起沉浸在《恋爱季节》',
      ),
    'bf'=>array(
      'title' =>'幸福满家园',
      'day'=>'67',
      'index'=>605,
      'lywx'=>302,
      'category'=>'婚恋家庭',
      'desc'=>'幸福人生是我们的希望，美满家庭是我们的追求；在家园里学习爱和关怀，在家园里学习耕耘和灌溉；让爱的种子生长、开花、结果，让我们的家庭成为合神心意的基督化家庭！',
      ),
    'up'=>array(
      'title' =>'亲情不断电',
      'day'=>'15',
      'index'=>606,
      'lywx'=>303,
      'category'=>'婚恋家庭',
      'desc'=>'有一种情，从你出生就已经存在；有一种情，就算是死亡也无法割舍；它，塑造我们鲜明的个性；它，教会我们珍惜彼此；它就是亲情，是我们一生的牵挂',
      ),
    'hg'=>array(
      'title' =>'欢乐卡恰碰',
      'day'=>'17',
      'index'=>607,
      'lywx'=>304,
      'category'=>'婚恋家庭',
      'desc'=>'小小的扭蛋，大大的欢笑，轻轻转扭的“卡恰”声，“碰”出许多神秘与惊喜！在这个专属儿童的乐园里，你可以和许多小朋友一起欢笑，一起学习！快来加入我们，让我们陪你成长，与你同乐',
      'feearadio'=>'1',
      ),
    'yu'=>array(
      'title' =>'绝妙当家',
      'day'=>'17',
      'index'=>608,
      'desc'=>'没有理由，不需要理由，你就是主角。绝对唯一，绝对独特，你是无可取代',
      'feearadio'=>'1',//http://media.feearadio.net/program/YU/yu-151214.mp3
      'lywx'=>104,
      'category'=>'生活智慧',
      ),
    'fc'=>array(
      'title' =>'微播出炉',
      'day'=>'15',
      'index'=>609,
      'lywx'=>101,
      'category'=>'生活智慧',
      'desc'=>'把社会话题与福音联系起来，在媒体中发出另一种声音，让听众了解圣经如何处理这些热门话题。',
      ),
    'gv'=>array(
      'title' =>'生活无国界',
      'day'=>'17',
      'index'=>610,
      'desc'=>'幽默风趣、欢声笑语，一个快乐你生活的节目，听了做梦都会笑 天南地北、古今中外，一扇开阔你视野的窗口，精彩世界看得见 紧密互动、开放参与，一个实现你梦想的平台，下一位DJ就是我 贴心关怀、专业辅导，一位陪伴你成长的夥伴，与你同行在爱中',
      'lywx'=>105,
      'category'=>'生活智慧',
      ),
    'zz'=>array(
      'title' =>'零点零距离',
      'day'=>'15',
      'index'=>611,
      'desc'=>'透过心灵隽语、诗歌、见证、心身灵健康讨论、时事评论、周末剧场等，让你修复人际关系，提升灵命，在工作场上，无往不利',
      'lywx'=>106,
      'category'=>'生活智慧',
      ),
    'bc'=>array(
      'title' =>'书香园地',
      'day'=>'15',
      'index'=>612,
      'desc'=>'打开心灵的窗户，让书香的味道飘洒进来；走进缤纷的园地，让生命的色彩丰富起来。邀请爱书人进入《书香园地》，细细品味书中的芬芳，与刘文和作者一起寻找心灵的交汇点',
      'feearadio'=>'1',
      'lywx'=>102,
      'category'=>'生活智慧',
      ),
    'ir'=>array(
      'title' =>'iradio爱广播',
      'day'=>'17',
      'index'=>613,
      'desc'=>'为你带出电台最新消息，最动听节目推介，也替电台寻找听电台、爱电台的知音人，分享生命的故事。台长也会定期出现，分享电台最新的政策，也与听众分享他的个人心声，勉励事奉',
      'lywx'=>107,
      'category'=>'生活智慧',
      ),
    'rt'=>array(
      'title' =>'今夜心未眠',
      'day'=>'67',
      'index'=>614,
      'desc'=>'冲一壶好茶，选一本好书，细细品读，慢慢分享，一场心与心的对话',
      'lywx'=>103,
      'category'=>'生活智慧',
      ),
    'tr'=>array(
      'title' =>'彩虹桥',
      'day'=>'15',
      'index'=>615,
      'lywx'=>402,
      'category'=>'诗歌音乐',
      'desc'=>'诗歌音乐:《彩虹桥》用诗歌搭起人与神之间的桥梁，带来弟兄姊妹与主更亲近，爱主更深，对主的信心也越发坚强',
      ),
    'ws'=>array(
      'title' =>'长夜的牵引',
      'day'=>'17',
      'index'=>616,
      'lywx'=>403,
      'category'=>'诗歌音乐',
      'desc'=>'诗歌音乐:有一束光，用跳跃的音符，带领着你和我穿过长夜。那是牵引，那是爱，进入自由的天地，显明真理。长夜的牵引，和你一起离开黑暗，迎向那光！',
      ),
    'gn'=>array(
      'title' =>'现代人的希望',
      'day'=>'15',
      'index'=>617,
      'lywx'=>502,
      'category'=>'慕道探索',
      'desc'=>'疲累、焦虑、寂寞、压力，构筑出现代人的共同困境。唯有来自永恒的声音，才能抚慰虚空的心灵。圣经是迷途者的指南，耶稣是现代人的希望。一个给你带来永恒盼望的节目',
      ),
    'dy'=>array(
      'title' =>'献上今天',//ns 生命的四季
      'day'=>'15',
      'index'=>618,
      'lywx'=>602,
      'category'=>'生命成长',
      'desc'=>'生命的四季',
      ),
    'ee'=>array(
      'title' =>'拥抱每一天',
      'day'=>'17',
      'index'=>619,
      'lywx'=>603,
      'category'=>'生命成长',
      'desc'=>'生命能够成长，因为我们愿意放下昨天；生命是那么的美好，因为我们拥有今天；生命充满希望，因为我们可以计划明天',
      ),
    'mw'=>array(
      'title' =>'旷野吗哪',
      'day'=>'17',
      'index'=>620,
      'lywx'=>601,
      'category'=>'生命成长',
      'desc'=>'与你分享灵修材料，以亲切并深入关怀生活层面的讲解，为你传达明确清晰的圣经信息，帮助你应用于信仰生活上，好叫信徒珍爱灵修，灵命长进！',
      ),
    'be'=>array(
      'title' =>'真道分解',
      'day'=>'17',
      'index'=>621,
      'lywx'=>701,
      'category'=>'学习真道',
      'desc'=>'透过经卷研读，陪伴你建立真理基础，栽培你灵命成长，帮助你活出信仰',
      ),
    'bs'=>array(
      'title' =>'圣言盛宴',
      'day'=>'67',
      'index'=>622,
      'lywx'=>702,
      'category'=>'学习真道',
      'desc'=>'透过小组查经的方式与呈现，带领听众明白神的圣言，领受属灵的丰盛筵席',
      ),
    'cw'=>array(
      'title' =>'齐来颂扬',
      'day'=>'15',
      'index'=>623,
      'desc'=>'诗歌音乐:精选古今中外赞美圣诗，带领信徒齐来敬拜，同心颂扬万王之王，万主之主！',
      'lywx'=>401,
      'category'=>'诗歌音乐',
      ),
    'tg'=>array(
      'title' =>'施恩座前',
      'day'=>'17',
      'index'=>624,
      'lywx'=>604,
      'category'=>'生命成长',
      'desc'=>'一起祷告、学习、分享、互动，培养属灵操练的习惯，建立同心同行的关系',
      ),
    'th'=>array(
      'title' =>'真理之光',
      'day'=>'17',
      'index'=>625,
      'lywx'=>609,
      'category'=>'生命成长',
      'desc'=>'带领弟兄姊妹更深入认识圣经真理，让神的话语成为我们生命中随时的提醒、帮助、鼓励、安慰和引导，让我们喜乐的事奉神，荣耀神，为神做美好的见证！',
      ),
    'pb'=>array(
      'title' =>'接棒人',
      'day'=>'15',
      'index'=>626,
      'lywx'=>1001,
      'category'=>'栽培训练',
      'desc'=>'为教会领袖和事奉人员提供神学和教义训练，着重知识与灵命培育，并装备学员参与事奉与牧养，成为新一代的接棒人',
      ),
    'hw'=>array(
      'title' =>'聆听主道',
      'day'=>'67',
      'index'=>627,
      'lywx'=>703,
      'category'=>'学习真道',
      'desc'=>'神所重用的仆人，为当代信徒讲解圣经真道，让我们一同安静下来，靠近主脚前，用心聆听主道',
      ),
    'aw'=>array(
      'title' =>'空中崇拜',
      'day'=>'7',
      'index'=>628,
      'lywx'=>606,
      'category'=>'生命成长',
      'desc'=>'空中崇拜',
      ),
    'yp'=>array(
      'title' =>'善牧良言',
      'day'=>'7',
      'index'=>629,
      'lywx'=>706,
      'category'=>'学习真道',
      'desc'=>'透过神所重用的牧者，结合他们多年的牧养、带领，以及丰富的人生历练，融入释经讲道的分享来建造听众，使我们因神的道而成长',
      ),
    'gsa'=>array(
      'title' =>'好牧人',
      'day'=>'7',
      'index'=>630,
      'lywx'=>705,
      'category'=>'学习真道',
      'desc'=>'本节目邀请神的仆人分享，供应神的话语，满足你的灵命需求，使得生命更丰盛',
      ),
    'ba'=>array(
      'title' =>'经动人心',
      'day'=>'7',
      'index'=>631,
      'lywx'=>704,
      'category'=>'学习真道',
      'desc'=>'基于圣经，加上创意，化作动人心弦的圣经广播剧。一起走进圣经人物的生命，体会他们的喜怒哀乐，认识救主耶稣基督，激励我们在生活中实践信仰',
      ),
    'bm'=>array(
      'title' =>'佳美脚踪',
      'day'=>'6',
      'index'=>632,
      'lywx'=>608,
      'category'=>'生命成长',
      'desc'=>'佳美脚踪',
      ),
    'hd'=>array(
      'title' =>'蓝天绿洲',
      'day'=>'67',
      'index'=>633,
      'lywx'=>801,
      'category'=>'中英双语',
      'desc'=>'中英双语:想谋生？想人生？想生活？想生命？都可以一起来想。爱英语？爱思考？爱音乐？爱真理？也不妨共同去爱！',
      ),
    'sr'=>array(
      'title' =>'给力人生',
      'day'=>'15',
      'index'=>634,
      'lywx'=>611,
      'category'=>'生命成长',
      'desc'=>'本节目为初信栽培而设，透过不同的课题，包括生命读经，家庭规划，自我探索，让信仰落实到生活的每个层面，为我们的人生给力',
      ),
    // 'dp'=>array(
    //   'title' =>'空中门训',
    //   'day'=>'15',
    //   'index'=>635,
    //   'lywx'=>613,
    //   'category'=>'生命成长',
    //   'desc'=>'空中门训',
    //   ),
    'bb'=>array(
      'title' =>'生根建造',
      'day'=>'135',
      'index'=>636,
      'lywx'=>610,
      'category'=>'生命成长',
      'desc'=>'生根建造',
      ),
    'tu'=>array(
      'title' =>'信仰百宝箱',
      'day'=>'135',
      'index'=>637,
      'lywx'=>612,
      'category'=>'生命成长',
      'desc'=>'借查考圣经和分享信徒生活专题，让信徒对信仰及生活有更明确的方向，面对生活的种种挑战时，能以圣经真理作行事为人的基础',
      ),
    'iv'=>array(
      'title' =>'生活之光',
      'day'=>'67',
      'index'=>638,
      'lywx'=>708,
      'category'=>'学习真道',
      'desc'=>'本节目是史温道牧师（Charles Swindoll）30多年来之讲道选集。节目包含三个讲道系列：在恩典中觉醒、奏出原本婚姻的乐章和旧约圣经人物的奇妙故事。讲道以圣经真理为基础，并融汇历代基督徒作家、神学家和知名牧者的观点论据，配合生活化的例子和个人经历，深入浅出，历久弥新，对信徒与非信徒的生命必能有所造就。',
      ),
    'gl'=>array(
      'title' =>'生命的福音',
      'day'=>'7',
      'index'=>639,
      'desc'=>'生命的福音',
      'lywx'=>501,
      'category'=>'慕道探索',
      ),
    'mp'=>array(
      'title' =>'这一刻清心',
      'day'=>'67',
      'index'=>640,
      'desc'=>'这一刻，清心',
      'lywx'=>605,
      'category'=>'生命成长',
      ),
    'ds'=>array(
      'title' =>'晨曦讲座',
      'day'=>'17',
      'index'=>646,
      'lywx'=>1002,
      'category'=>'栽培训练',
      'desc'=>'拓展视野，关心教会发展，按照真理共建神家，放眼世界禾场，努力实践晨曦异象',
      ),
    'vc'=>array(
      'title' =>'良院专区',//vx良院精选
      'day'=>'7',
      'index'=>647,
      'lywx'=>1003,
      'category'=>'栽培训练',
      'desc'=>'良院精选',
      ),
    'wa'=>array(
      'title' =>'天路导向',
      'day'=>'7',
      'index'=>648,
      'lywx'=>802,
      'category'=>'中英双语',
      'desc'=>'中英双语:以主题信息讲座的方式，配以诗歌、祷告、内容简介和扼要总结，让信息传达更清晰，使记忆更深刻。逐句英译中讲道方式，灵性造就的同时，英文水平也得到操练与提高',
      ),
    'cwa'=>array(
      'title' =>'天路导向粤',
      'day'=>'7',
      'index'=>649,
      'lywx'=>803,
      'category'=>'中英双语',
      'desc'=>'中英双语:天路导向（粤语）以主题信息讲座的方式，配以诗歌、祷告、内容简介和扼要总结，让信息传达更清晰，使记忆更深刻。逐句英译中讲道方式，灵性造就的同时，英文水平也得到操练与提高',
      ),
    'gt'=>array(
      'title' =>'恩典与真理',
      'day'=>'7',
      'index'=>650,
      'lywx'=>901,
      'category'=>'少数民族',
      'desc'=>'少数民族:恩典与真理（回民）《恩典与真理》，引导你走上正义之路。愿你得着真主给你的色俩麦提和瑞孜给，因沙安拉。',
      ),
    'ynf'=>array(
      'title' =>'爱在人间',
      'day'=>'17',
      'index'=>651,
      'lywx'=>902,
      'category'=>'少数民族',
      'desc'=>'少数民族:爱在人间（云南话）谈天说地、细数民俗、倾听民歌、谈论信仰 ... 汇集成为彩云之南的特色节目，把主耶稣的爱向各族人民传讲',
      ),
    'ls'=>array(
      'title' =>'燃亮的一生',
      'day'=>'67',
      'index'=>652,
      'lywx'=>607,
      'category'=>'生命成长',
      'desc'=>'与你分享宣教士的生平和服侍，让我们一同体会信仰的生命力，盼望你与我们一起多关心宣教，一同活出燃亮的生命！',
      ),
    'it'=>array(
      'title' =>'与神同行',//tp 真理与柱石
      'day'=>'5',
      'index'=>654,
      'lywx'=>707,
      'category'=>'学习真道',
      'desc'=>'透过经卷研读，陪伴你建立真理基础，栽培你灵命成长，帮助你活出信仰',
      ),
    'hdb'=>array(
      'title' =>'蔚蓝心情',
      'day'=>'5',//????
      'index'=>655,
      'lywx'=>804,
      'category'=>'中英双语',
      'desc'=>'透过经卷研读，陪伴你建立真理基础，栽培你灵命成长，帮助你活出信仰',
      ),
    'sg'=>array(
      'title' =>'津津乐道',
      'day'=>'5',//????
      'index'=>656,
      'lywx'=>503,
      'category'=>'慕道探索',
      'desc'=>'透过经卷研读，陪伴你建立真理基础，栽培你灵命成长，帮助你活出信仰',
      ),
    'ltsfp'=>array(
      'title' =>'基础课程',
      'day'=>'7',
      'index'=>641,
      'lywx'=>1641,
      'category'=>'栽培训练',
      'desc'=>'基础课程',
      ),
    'ltsdp1'=>array(
      'title' =>'本科1',
      'day'=>'7',
      'index'=>642,
      'lywx'=>1642,
      'category'=>'栽培训练',
      'desc'=>'本科文凭课程1',
      ),
    'ltsdp2'=>array(
      'title' =>'本科2',
      'day'=>'7',
      'index'=>643,
      'lywx'=>1643,
      'category'=>'栽培训练',
      'desc'=>'本科文凭课程2',
      ),
    'ltshdp1'=>array(
      'title' =>'进深1',
      'day'=>'7',
      'index'=>644,
      'lywx'=>1644,
      'category'=>'栽培训练',
      'desc'=>'进深文凭课程1',
      ),
    'ltshdp2'=>array(
      'title' =>'进深2',
      'day'=>'7',
      'index'=>645,
      'lywx'=>1645,
      'category'=>'栽培训练',
      'desc'=>'进深文凭课程2',
      ),
    'tm'=>array(
      'title' =>'我们仨，还有你',
      'day'=>'67',
      'index'=>653,
      'desc'=>'2016-10-30',
      'lywx'=>108,
      'category'=>'生活智慧',
      ),
    'bk'=>array(
      'title' =>'听书‧想飞',
      'day'=>'7',
      'index'=>656,
      'desc'=>'2016-10-30',
      'lywx'=>109,
      'category'=>'生活智慧',
      ),
  );

}

// $ly = liangyou_audio_list2();
// dpm($ly);
// $json = drupal_json_encode($ly);
// dpm($json);
// 【635】听书‧想飞//空中门训->0

function ly_stream_menu(){
  return '▶良友广播节目单
  ----------------------------------------------
  生活智慧
  【609】微播出炉
  【612】书香园地
  【614】今夜心未眠
  【608】绝妙当家
  【610】生活无国界
  【611】零点零距离
  【613】 爱广播
  【653】我们仨，还有你
  【635】听书‧想飞
  关怀辅导
  【603】空中辅导
  【601】无限飞行号
  【602】 心磁场
  婚恋家庭
  【604】恋爱季节
  【605】幸福满家园
  【606】亲情不断电
  【607】欢乐卡恰碰
  诗歌音乐
  【623】齐来颂扬
  【615】彩虹桥
  【616】长夜的牵引
  慕道探索
  【639】生命的福音
  【617】现代人的希望
  【656】津津乐道
  生命成长
  【620】旷野吗哪
  【618】献上今天
  【619】拥抱每一天
  【624】施恩座前
  【640】这一刻清心
  【628】空中崇拜
  【652】燃亮的一生
  【632】佳美脚踪
  【625】真理之光
  【636】生根建造
  【634】给力人生
  【637】信仰百宝箱
  学习真道
  【621】真道分解
  【622】圣言盛宴
  【627】聆听主道
  【631】经动人心
  【630】好牧人
  【629】善牧良言
  【654】与神同行
  【638】生活之光
  中英双语
  【633】蓝天绿洲
  【648】天路导向
  【649】天路导向粤
  【655】蔚蓝心情
  少数民族
  【650】恩典与真理
  【651】爱在人间
  栽培训练
  【626】接棒人
  【646】晨曦讲座
  【647】良院专区
   回复【】内容[调皮]不带中括号
   点击►收听[抱拳]';
}
//TODO delete!!!
function lywx_menu(){
  return
  '输入以下数字代号，可以收听良友电台相关的节目：

  生活智慧
  101：微播出炉
  102：书香园地
  103：今夜心未眠
  104：绝妙当家
  105：生活无国界
  106：零点零距离
  107：iradio爱广播

  关怀辅导
  201：空中辅导
  202：无限飞行号
  203：i关怀心磁场

  婚恋家庭
  301：恋爱季节
  302：幸福满家园
  303：亲情不断电
  304：欢乐卡恰碰

  诗歌音乐
  401：齐来颂扬
  402：彩虹桥
  403：长夜的牵引

  慕道探索
  501：生命的福音
  502：现代人的希望
  503：津津乐道

  生命成长
  601：旷野吗哪
  602：生命的四季
  603：拥抱每一天
  604：施恩座前
  605：这一刻清心
  606：空中崇拜
  607：燃亮的一生
  608：佳美脚踪
  609：真理之光
  610：生根建造
  611：给力人生
  612：信仰百宝箱
  613：空中门训

  学习真道
  701：真道分解
  702：圣言盛宴
  703：聆听主道
  704：经动人心
  705：好牧人
  706：善牧良言
  707：与神同行
  708：生活之光

  中英双语
  801：蓝天绿洲
  802：天路导向
  803：天路导向粤

  少数民族
  901：恩典与真理
  902：爱在人间

  栽培训练
  1001：接棒人
  1002：晨曦讲座
  1003：良院精选';
  }
