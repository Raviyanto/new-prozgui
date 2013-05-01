/******************************************************************************
 fltk prozilla - a front end for prozilla, a download accelerator library
 Copyright (C) 2001 Kalum Somaratna

 FLTK PROZGUI - a GUI download accelerator
 Copyright (C) 2011 Raviyanto Ahmad

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
******************************************************************************/
#include <libintl.h>
#include "ftps_win.h"
#include <assert.h>
#include <string.h>
#include <FL/x.H>

#    ifdef HAVE_LIBXPM
#      include <X11/xpm.h>
#    endif

/* XPM */
static const char *Prozgui2_xpm[] = {
"32 32 422 2",
"  	c None",
". 	c #ABAEAB",
"+ 	c #686968",
"@ 	c #232323",
"# 	c #181818",
"$ 	c #151515",
"% 	c #262625",
"& 	c #2E2E2E",
"* 	c #202020",
"= 	c #313130",
"- 	c #2D2C2C",
"; 	c #3C3B3B",
"> 	c #403F3F",
", 	c #4F4E4E",
"' 	c #4F4E4D",
") 	c #484747",
"! 	c #3F3E3E",
"~ 	c #464645",
"{ 	c #6A6867",
"] 	c #61605F",
"^ 	c #848280",
"/ 	c #8D8B88",
"( 	c #8F8D8A",
"_ 	c #444443",
": 	c #191818",
"< 	c #1A1A1A",
"[ 	c #0C0B0A",
"} 	c #201F1F",
"| 	c #343333",
"1 	c #252525",
"2 	c #393938",
"3 	c #363535",
"4 	c #333232",
"5 	c #474646",
"6 	c #373636",
"7 	c #383737",
"8 	c #4A4A4A",
"9 	c #454444",
"0 	c #525150",
"a 	c #5C5A5A",
"b 	c #7D7A78",
"c 	c #878582",
"d 	c #A0A19F",
"e 	c #31302F",
"f 	c #070605",
"g 	c #1C1B1A",
"h 	c #11100F",
"i 	c #1D1D1D",
"j 	c #212121",
"k 	c #414040",
"l 	c #4B4A49",
"m 	c #3E3D3D",
"n 	c #464545",
"o 	c #494847",
"p 	c #434242",
"q 	c #4E4D4D",
"r 	c #444343",
"s 	c #3A3939",
"t 	c #575655",
"u 	c #504F4F",
"v 	c #6C6A69",
"w 	c #92908C",
"x 	c #3A3A3A",
"y 	c #292828",
"z 	c #2D2D2D",
"A 	c #222221",
"B 	c #2F2F2E",
"C 	c #4A4949",
"D 	c #4B4B4A",
"E 	c #535252",
"F 	c #383837",
"G 	c #898785",
"H 	c #969491",
"I 	c #282727",
"J 	c #252424",
"K 	c #2D2D2C",
"L 	c #424141",
"M 	c #494848",
"N 	c #545352",
"O 	c #393838",
"P 	c #4D4C4B",
"Q 	c #3B3A3A",
"R 	c #323232",
"S 	c #696867",
"T 	c #7F7C7A",
"U 	c #868582",
"V 	c #969592",
"W 	c #A3A3A0",
"X 	c #302F2F",
"Y 	c #262626",
"Z 	c #292928",
"` 	c #4D4D4C",
" .	c #5A5959",
"..	c #5F5E5E",
"+.	c #575656",
"@.	c #676565",
"#.	c #686665",
"$.	c #757473",
"%.	c #84807E",
"&.	c #7E7C7A",
"*.	c #181717",
"=.	c #131212",
"-.	c #1B1A1A",
";.	c #313030",
">.	c #2B2A2A",
",.	c #6B6A69",
"'.	c #70625D",
").	c #66544D",
"!.	c #947569",
"~.	c #7B6D66",
"{.	c #685C58",
"].	c #83817E",
"^.	c #767371",
"/.	c #726E6D",
"(.	c #979796",
"_.	c #1B1B1A",
":.	c #161515",
"<.	c #282828",
"[.	c #1F1F1E",
"}.	c #282827",
"|.	c #3D3C3C",
"1.	c #2F2E2E",
"2.	c #353535",
"3.	c #544642",
"4.	c #915E4C",
"5.	c #C49C8D",
"6.	c #A08A7F",
"7.	c #936C5E",
"8.	c #A1948E",
"9.	c #51504E",
"0.	c #8B8986",
"a.	c #898784",
"b.	c #868280",
"c.	c #83807E",
"d.	c #767473",
"e.	c #323131",
"f.	c #1C1C1B",
"g.	c #1A1A19",
"h.	c #2B2B2A",
"i.	c #4C4B4B",
"j.	c #555454",
"k.	c #5D5C5C",
"l.	c #514F4E",
"m.	c #4A4948",
"n.	c #434241",
"o.	c #62493F",
"p.	c #B28F83",
"q.	c #8D7165",
"r.	c #443733",
"s.	c #A06854",
"t.	c #9C7061",
"u.	c #352722",
"v.	c #454443",
"w.	c #6F6D6B",
"x.	c #797775",
"y.	c #7E7A78",
"z.	c #110F0E",
"A.	c #252524",
"B.	c #504F4E",
"C.	c #616060",
"D.	c #595858",
"E.	c #535251",
"F.	c #674C44",
"G.	c #905C4C",
"H.	c #7B5548",
"I.	c #8B7166",
"J.	c #C28F7C",
"K.	c #A37867",
"L.	c #834F3F",
"M.	c #4E403C",
"N.	c #666564",
"O.	c #232222",
"P.	c #2E2D2D",
"Q.	c #323231",
"R.	c #4B4A4A",
"S.	c #5C5A59",
"T.	c #595857",
"U.	c #2C2B2B",
"V.	c #483B37",
"W.	c #754F42",
"X.	c #744F41",
"Y.	c #6A4437",
"Z.	c #474645",
"`.	c #625F5E",
" +	c #706E6D",
".+	c #5E5D5C",
"++	c #2A2A29",
"@+	c #5D5C5B",
"#+	c #676665",
"$+	c #373736",
"%+	c #5C5B5B",
"&+	c #666565",
"*+	c #5B5A59",
"=+	c #272626",
"-+	c #353434",
";+	c #605F5F",
">+	c #565554",
",+	c #646363",
"'+	c #565555",
")+	c #555453",
"!+	c #4C4B4A",
"~+	c #1E1E1D",
"{+	c #2C2C2C",
"]+	c #3C3C3B",
"^+	c #2C2C2B",
"/+	c #5B5A5A",
"(+	c #5E5D5D",
"_+	c #5F5D5C",
":+	c #605E5D",
"<+	c #515050",
"[+	c #343433",
"}+	c #222222",
"|+	c #232322",
"1+	c #272727",
"2+	c #454544",
"3+	c #5F5E5D",
"4+	c #8C8986",
"5+	c #8F8C89",
"6+	c #585655",
"7+	c #686767",
"8+	c #525151",
"9+	c #585757",
"0+	c #6D6B6B",
"a+	c #94928E",
"b+	c #A5A3A0",
"c+	c #B0B2AF",
"d+	c #B8B9B6",
"e+	c #C0C3BF",
"f+	c #BBBCB8",
"g+	c #A4A6A3",
"h+	c #989591",
"i+	c #8C8A87",
"j+	c #7B7977",
"k+	c #2E2E2D",
"l+	c #30302F",
"m+	c #333332",
"n+	c #7B7876",
"o+	c #9C9A97",
"p+	c #AAA9A6",
"q+	c #B3B4B1",
"r+	c #CACEC9",
"s+	c #D3D7D2",
"t+	c #D4DCD5",
"u+	c #C3CAC6",
"v+	c #BCBFBC",
"w+	c #E0E7DF",
"x+	c #B7B9B6",
"y+	c #BABFBB",
"z+	c #B4B6B3",
"A+	c #9A9997",
"B+	c #868583",
"C+	c #5D5B5B",
"D+	c #121111",
"E+	c #B2B5B1",
"F+	c #C0C3C0",
"G+	c #D1D3CE",
"H+	c #DDDFD7",
"I+	c #E5E7DE",
"J+	c #E4E6DD",
"K+	c #D9E4DC",
"L+	c #CFD7D2",
"M+	c #B3B5B3",
"N+	c #BABDBA",
"O+	c #CFDCD5",
"P+	c #B6BAB7",
"Q+	c #AFAFAC",
"R+	c #B9BAB7",
"S+	c #92918E",
"T+	c #636261",
"U+	c #636262",
"V+	c #181716",
"W+	c #3E3E3D",
"X+	c #AAAAA6",
"Y+	c #C6CBC6",
"Z+	c #D4D7D1",
"`+	c #E7E8DF",
" @	c #E4E5DD",
".@	c #E2EBE2",
"+@	c #E7F1E7",
"@@	c #E2F0E6",
"#@	c #DDEDE4",
"$@	c #999895",
"%@	c #918F8C",
"&@	c #BDC5C1",
"*@	c #DAECE3",
"=@	c #B8B8B5",
"-@	c #B6B8B5",
";@	c #A4A29F",
">@	c #878482",
",@	c #262525",
"'@	c #444342",
")@	c #626161",
"!@	c #9A9793",
"~@	c #B5B8B5",
"{@	c #CACECA",
"]@	c #EBEEE4",
"^@	c #DCECE3",
"/@	c #F3F8ED",
"(@	c #EDF5EB",
"_@	c #D9E9E1",
":@	c #CED6D0",
"<@	c #A7A8A6",
"[@	c #BBC0BD",
"}@	c #C0C6C0",
"|@	c #9D9C99",
"1@	c #C5CEC8",
"2@	c #CDD7D1",
"3@	c #4D4C4C",
"4@	c #817E7C",
"5@	c #AEB0AC",
"6@	c #CCD5CF",
"7@	c #DADFD8",
"8@	c #E1EAE1",
"9@	c #E8F3E9",
"0@	c #D1D9D3",
"a@	c #CBD2CD",
"b@	c #C1C5C1",
"c@	c #B9BDBA",
"d@	c #B5B6B2",
"e@	c #CAD3CE",
"f@	c #A5A4A2",
"g@	c #B5BAB5",
"h@	c #41403F",
"i@	c #797674",
"j@	c #B0B0AE",
"k@	c #CED0CB",
"l@	c #DDE1DA",
"m@	c #D6DED7",
"n@	c #DBE9E0",
"o@	c #DEECE3",
"p@	c #D6E4DC",
"q@	c #D9DBD4",
"r@	c #D6D7D1",
"s@	c #B9BBB7",
"t@	c #C5CDC7",
"u@	c #5E3B3F",
"v@	c #71454A",
"w@	c #866467",
"x@	c #786567",
"y@	c #616161",
"z@	c #5B5B5B",
"A@	c #6E6C6B",
"B@	c #9B9B99",
"C@	c #C6CEC9",
"D@	c #C0C6C2",
"E@	c #B0B2B0",
"F@	c #BBA9AB",
"G@	c #C9B8B8",
"H@	c #DDE4DC",
"I@	c #E4B4B8",
"J@	c #F3E4DE",
"K@	c #EEBABD",
"L@	c #E3E8DF",
"M@	c #CED4CE",
"N@	c #C2C9C4",
"O@	c #C6C7C2",
"P@	c #CDD5CF",
"Q@	c #B06C74",
"R@	c #BD898F",
"S@	c #AD989B",
"T@	c #A3A3A3",
"U@	c #959595",
"V@	c #7E7E7E",
"W@	c #767574",
"X@	c #959492",
"Y@	c #A9A9A8",
"Z@	c #A7A8A7",
"`@	c #AC9DA0",
" #	c #B4B9B6",
".#	c #CC7281",
"+#	c #D0B1B2",
"@#	c #C3ADAE",
"##	c #B58D94",
"$#	c #AAABAA",
"%#	c #A7A7A6",
"&#	c #B2B3B2",
"*#	c #606060",
"=#	c #A69193",
"-#	c #909090",
";#	c #747474",
">#	c #757575",
",#	c #6A6A6A",
"'#	c #7C7C7C",
")#	c #9C9B9B",
"!#	c #A69E9F",
"~#	c #A6A3A3",
"{#	c #858585",
"]#	c #14370C",
"^#	c #16390E",
"/#	c #4E6349",
"(#	c #9D999A",
"_#	c #989797",
":#	c #969696",
"<#	c #939793",
"[#	c #193A11",
"}#	c #334E2D",
"|#	c #5B6D57",
"1#	c #183A10",
"2#	c #5D6E59",
"3#	c #1B3C14",
"4#	c #4C6147",
"5#	c #375231",
"6#	c #4D6248",
"7#	c #8D928C",
"8#	c #1C3D15",
"9#	c #858C84",
"0#	c #41593C",
"a#	c #576953",
"b#	c #1A3C13",
"c#	c #717D6E",
"d#	c #969995",
"e#	c #173910",
"f#	c #888E86",
"g#	c #5C6E58",
"h#	c #1E3F17",
"i#	c #24431D",
"j#	c #193B11",
"k#	c #445B3F",
"l#	c #3C5536",
"m#	c #7B7B7B",
"n#	c #646464",
"o#	c #908F8F",
"    . + @ # $ % & * = - ; > , > ' ) ! ~ { ] ^ / (               ",
"    _ : < [ [ } | 1 2 3 > 4 > 5 > 6 7 8 9 0 a b c (             ",
"d e f $ g h i i 4 j k 3 ) l m n o ! p q r s t u v w             ",
"x f f $ < $ y z A B C > r 5 5 ) 0 D C q p 9 E F , G H           ",
"< < [ $ @ i I J K p ! L M N O P q 3 Q ; F R m S T U V W         ",
"h < h * < < X Y Z ` m Q k 9 ! , _ > 9  ...+.@.#.$.U %.&.%.      ",
"*.=.$ * -.$ 4 A ;.Q ! - >.- i 7 > ! ,.'.).!.~.{.Q L ].c ^./.(.  ",
"_.:.# <.= @ [.}.Q |.; 1.O |.X ~ 2.n 3.4.5.6.7.8.Q o 9.0.a.b.c.d.",
"e.f.g.4 % h.| ; r i.i.> j.q L k.l.m.n.o.p.q.r r.s.t.u.v.w.x.b y.",
"B g.z.A.} X e.I Q E i.B.C.D.5 k.E.j.k.m F.G.H.I.J.K.L.M.6 k N.  ",
"* < [.A O.P.Q.2 R.+.' R.j.q n S.p 5 T.9 h.U.V.W.X.Y.X Z.r `. +.+",
"< < j ++>.} I s q i.' R.@+q m.#+9 M T.q C ! 2.K $+s > ' ) %+&+*+",
"*.*.} =+Z @ z }.-+-+R.) ;+>+i.k.u i.,+'+)+T.E.!+j.q @+D.D.D.+.+.",
"~+~+{+1.]+^+A.3 5 5 k r ;+@+@+{ /+' ,+'+] ,+'+(+_+L @+C.' :+<+[+",
"}+}+|+U.4 i 1+@ 2+3+v.Q .+c.( V 4+4+H 5+U U v 6+7+8+@+n.0 8+9+L ",
"y z U.4 K % ++^+M *+v.l 0+c.a+b+c+d+e+f+g+g+h+h+i+j+;+, 0 8+(++.",
"P.@ k+Y l+g.% m+! l N +.n+o+p+q+r+s+t+u+v+w+x+c+y+z+A+B+N.C+, N ",
"D+f.;.|.- g.% ; r L /+..T E+F+G+H+I+J+K+G+L+M+N+O+P+Q+R+g+S+T+U+",
"V+B 6 -+<.>.;.W+l n t /+T X+Y+Z+`+ @.@+@@@#@O+P+$@%@&@*@=@-@;@>@",
",@|.6 L * P.}+'@m n )@R.{ !@~@{@ @]@^@+@/@(@_@:@v+<@[@}@|@1@2@X+",
"4 O | m i <.e.9 R.^+3@n 3+4@5@6@7@8@*@*@9@9@/@@@0@a@b@c@d@e@f@g@",
"p k+s k < * }+h@e.4 B.) 3+i@5+j@k@l@m@n@#@#@/@(@o@o@p@p@q@r@s@t@",
"m u@v@w@x@y@z@D |.s ! Q C A@b B@C@D@E@F@G@H@I@J@J@K@L@M@N@N@O@P@",
"9 Q@R@S@T@T@U@V@,+3@R.'+3@] W@X@Y@Z@T@T@`@ #.#+#@###$#%#T@T@$#&#",
"*#=#T@T@T@T@T@T@-#;#&+>#>#,#'#)#T@T@T@T@T@T@!#~#T@T@T@T@T@T@T@T@",
"{#T@T@]#^#/#T@T@T@(#(#T@T@_#(#T@T@T@T@T@T@T@T@T@T@T@]#T@T@T@T@T@",
":#T@T@]#<#[#T@]#}#T@|#1#2#T@]#]#3#T@4#5#]#T@]#T@]#T@]#T@T@T@T@T@",
"T@T@T@]#^#6#T@]#7#T@8#9#8#T@T@0#a#T@b#9#]#T@]#T@]#T@]#T@T@T@T@T@",
"T@T@T@]#T@T@T@]#T@T@8#9#8#T@c#[#d#T@b#9#]#T@e#f#]#T@]#T@T@T@T@T@",
"U@T@T@]#T@T@T@]#T@T@|#e#g#T@h#]#]#T@4#i#j#T@k#l#]#T@]#T@T@T@T@T@",
"m#T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@",
"n#o#T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@"};

ftps_gui::ftps_gui():Fl_Window(300,389) {
  Fl_Window* w;
  { Fl_Window* o = ftps_win = this;
    w = o;
    o->user_data((void*)(this));

#ifdef HAVE_LIBXPM                // X11 w/Xpm library
    fl_open_display();
    Pixmap pixmap, mask;          // Icon pixmaps
    XpmAttributes attrs;          // Attributes of icon

    memset(&attrs, 0, sizeof(attrs));

    XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
                            const_cast<char **>(Prozgui2_xpm), &pixmap, &mask, &attrs);
    o->icon((char *) pixmap);
#endif

    { Fl_Output* o = ftps_file_box = new Fl_Output(70, 10, 220, 25, gettext("Filename::"));
      o->box(FL_ENGRAVED_BOX);
      o->color(49);
      o->labelsize(12);
      o->labelcolor(4);
      o->textsize(12);
      o->textcolor(4);
      o->align(132);
    }
    { Fl_Browser* o = mirror_browser = new Fl_Browser(20, 60, 260, 135);
      o->labelsize(12);
      o->textsize(12);
      o->align(129);
    }
    { Fl_Return_Button* o = exit_ftpsearch_button = new Fl_Return_Button(90, 365, 120, 20, gettext("Start Download"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_exit_ftpsearch, (void*)(this));
    }
    { Fl_Browser* o = message_browser = new Fl_Browser(20, 220, 260, 135);
      o->labelsize(12);
      o->textsize(12);
    }
    { Fl_Box* o = new Fl_Box(20, 40, 70, 20, gettext("Mirrors"));
      o->labelsize(12);
      o->align(132|FL_ALIGN_INSIDE);
    }
    { Fl_Box* o = new Fl_Box(205, 40, 75, 20, gettext("Ping Time"));
      o->labelsize(12);
      o->align(132|FL_ALIGN_INSIDE);
    }
    o->show();
    o->end();
  }
}