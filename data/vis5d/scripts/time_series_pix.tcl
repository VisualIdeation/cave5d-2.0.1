set name	time_series_pic
set format	VIS5D_GIF
set ext		gif


set nframes [ vis5d_get_dtx_numtimes 0 ]

for { set iframe 0 } { $iframe < $nframes } { incr iframe } {

	set file_name [ format "%s%4.4d.%s" $name $iframe $ext ]
	vis5d_set_dtx_timestep 0 $iframe
	vis5d_save_window 0 $file_name $format
}
