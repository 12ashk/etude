# /usr/bin/env perl 
# -*- coding: utf-8 -*-
#後ろの二文字の数字だけ取り出してrename

foreach (glob("*.jpg")){
	chomp;
	if(/(\d{2}\.jpg)/){
		rename $_, $&;
	}
}
