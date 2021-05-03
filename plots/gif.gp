set terminal gif animate delay 1
set output 'advection_hat_100k.gif'


#set size square
set yrange [0.0:1.1]

do for [i=0:249] {
    set title "Steps: ".i*400
    plot sprintf('../build/gif_dir/%d.dat', i*400) with lines lc rgb '#039053' lw 5 notitle
} 


reset 
set output
set terminal qt #just to return back to normal output terminal; might not be qt on your system
 
 
