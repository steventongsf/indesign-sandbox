//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/textimportfilter/examplefiles/JIS.cpp $
//  
//  Owner: ???
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

$B$3$l$O(BJIS$B$N%U%!%$%k$G$9!#(B

$B0u:~$NNr;K(B
$B>pJs$NEAC#J}K!$H$7$F$N0u:~(B
$B!A3hHG0u:~$NF|K\Ia5Z(B

$B;d$?$A$NJk$i$7$K$H$C$F!"$-$o$a$FL)@\$J4X78$K$"$k0u:~!"0u:~5;=Q$O$$$C$?$$$I$N$h$&$JF;6Z$r$?$I$C$F:#F|$K;j$C$?$N$@$m$&$+!)>pJs$NEAC#$H5-O?!#$3$l$O@$3&$KJ8L@$,H/>M$7$F0JMh!"?MN`$,<h$jAH$s$G$-$?:G$b=EMW$J9T0Y$N$R$H$D$G$"$k!#>pJs$NEAC#J}K!$H$7$F8=:_$K$D$J$,$k0u:~$,:G$bAa$/;O$^$C$?$N$OCf9q$G$"$k!#$=$N5/8;$,$$$D$G$"$C$?$+$O@53N$G$O$J$$$,!"#8@$5*$b$7$/$O$=$l$h$j>/$70JA0$N;~Be$H9M$($i$lLZHG0u:~$,9T$J$o$l$F$$$?$H9M$($i$l$k!#$3$NCf9q$G;O$^$C$?0u:~=Q$O!"F`NI;~Be$K@=;f5;=Q$H$H$b$KF|K\$KEAMh$7$?!#(B
$B0lJ}!"$3$N$h$&$KCf9q$G@8$^$l$?@=;fK!$H!"LZHG0u:~$H$,%h!<%m%C%Q$KEA$o$j!"6aBe0u:~=Q$r3+$/4pAC$H$J$C$?!#3hHG0u:~$O!"#1#5@$5*Cf:"%I%$%D$N%0!<%F%s%Y%k%0$K$h$C$FH/L@$5$l$?!#Ev;~%h!<%m%C%Q$G$O@;=q$J$I$N=PHG;v6H$,@9$s$K$J$C$?$,!"<j$G<L$9:n6H$O8m$j$,B?$/!"=EO+F/$G$"$C$?$?$a$=$N6lO+$r8+$F%0!<%F%s%Y%k%0$,0u:~=Q$r3+H/$7$?$H$$$o$l$F$$$k!#3hHG0u:~$NIa5Z$O!"%k%M%C%5%s%9$NJ87]I|6=$KBg$-$JLr3d$r2L$?$7$?$P$+$j$+!"%h!<%m%C%QJ8L@$N@-3J$r$bJQ2=$5$;$?!##1#5@$5*$N8eH>$K$OAa$/$b#8#0#0K|:}$NK\$,0u:~$5$l$?$H$$$&!#$3$N?t$O!"$=$l$^$G$K<LK\$K$h$C$F$D$/$i$l$?%h!<%m%C%Q$N$9$Y$F$N=qJ*$N?t$h$j$bB?$$$H9M$($i$l$k!#$3$l0J9_!"%h!<%m%C%Q$N0u:~=Q$OHtLvE*$KH/E8$r?k$2$k!#$^$?!"%$%.%j%9$K5/$3$C$?;:6H3WL?$K$h$C$F0u:~5!3#$NF0NO2=$H5;=Q$N?JE8$,<B8=$7$?!#$=$N3hHG0u:~$,!"F|K\$KEA$($i$l$?$N$O$=$N8e#1#4#0G/$r7P$?#1#5#9#0G/$N$3$H$G$"$C$?!#%m!<%^659D$N85$KGI8/$5$l$?E7@58/2%;H@a$N0l9T$rO"$l5"$C$?%$%(%:%92q@k65;U!"%P%j%K%c!<%K$,3hHG0u:~5!$H$=$N5!:`0l<0$*$h$SF<HG2h$ND&9oK!$rF|K\$K$b$?$i$7$?$N$G$"$k!#$7$+$7!"$;$C$+$/6lO+$7$FEA$($i$l$?3hHG0u:~$bK-?C=(5H$K$h$C$F;O$^$C$?%-%j%7%?%s6X05$N1F6A$G!"$o$:$+#2#0G/$[$I$G@d$($F$7$^$C$?!#KkKv$+$iL@<#;~Be$K$J$k$H!"2$JF$N0u:~5;=Q$,<!!9$K<h$jF~$l$i$l$?!#F|K\$K$*$1$k#2EYL\$N2$JF3hHG0u:~=Q$N;O$^$j$G$"$k!#(B
$B#1#8#5#5G/%*%i%s%@A%$,1?$s$@0u:~5!$r9XF~$7!"%*%i%s%@8l$N86=q$rI|9o$7$?$N$OK\LZ>;B$$G$"$C$?!#>;B$$O!"%Z%j!<$NN($$$k%"%a%j%+4OBb$,2<ED$KF~9A$N:]DLLu$K$"$?$j!"$5$i$KKkI\$NMW@A$K6(NO$9$k$3$H$K$h$j!"DL;l!"B$A%!">hA%A`=D$J$I$rDL$8$F309q?M$K2q$$!"3$30$NJ82=$d@h?J5;=Q$r5[<}$9$k$3$H$,$G$-$?!#>;B$$,K]Lu$d3hHG0u:~!"B$K\!"=PHG$N8&5f$K=E$-$r$*$$$?$N$OF|>o$NG$L3$NCf$GL\$K$7$?309q$N=qJ*$r!"F|K\$N8'3X!"MW?M!"Ip;N$KFI$^$;$?$$$H@ZK>$9$k$h$&$K$J$C$?$+$i$G$"$k!#(B
$B#1#8#5#0G/!XOBMvJ8E5J8>OJS!Y$rCx=R$7$?>;B$$O!"MbG/F|K\J8;z$N3h;z$N@=B$J}K!$r8&5f$7$F!"N.$79~$_3h;z!J3h;zCO6b$NJl7?$+$iCrB$$7$?3h;z!K$N@=B$$K@.8y$7$?!#$3$N;~>;B$$,:n$C$?3h;z$NBg$-$5$O!"=i9f$H#19f$+$i#79f$N#8<o$G$"$C$?!#(B
$B#1#8#6#9G/!"D9:j$K3hHGEA=,=j$r@_$1!"3h;z5;=Q$NM}O@$H<B5;$N%Y%F%i%s$G$"$C$?%"%a%j%+?M$N%,%s%V%k$r7^$(<BCO;XF3$r<u$1$?!#$=$NMbG/!J#1#8#7#0G/!K!">;B$$OD9G/$NM}A[$r<B8=$9$Y$/!"3hHG@=B$=j$r@_$1OBJ83hHG$r9)6H2=$7!"6aBe3hHG0u:~$N4pAC$rC[$$$?!#$5$i$KMbG/!J#1#8#7#1G/!K$K$OD>Do;R$NM[B6Fs$r2#IM$KGI8/$7!"$=$3$G3hHG=j$r3+@_$5$;$?!#$3$N3hHG=j$O$d$,$F!X2#IMKhF|?7J9!W!JF|K\:G=i$NF|4)?7J9!K$NAO4)$K$D$J$,$k!#$3$N?7J9$KMQ$$$i$l$?L@D+BN9f?t3h;z$O>;B$$N9M0F$K$h$k$b$N$G$"$k!#(B



