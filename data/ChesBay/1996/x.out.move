CAVE5D: attempting to allocate 536870912 bytes from shared memory.
vrShmemInit(): [31mWarning: shared memory already initialized, additional attempt ignored
[0m[0mFreeVR: [1m**** Configuring the System! ****
[0m[0m[0mFreeVR config: Reading string "Default Config String".
[0m[0mFreeVR config: [1mUsing system 'simulator'
[0m[0m[0m[31mSorry, Parsing of Prop options not yet implemented.
[0m[0m[0mFreeVR config: Done Parsing "Config string".  Read 125 lines.
[0m[0mFreeVR config: [1mReading file "/usr/local/freevr/.freevrrc".
[0m[0m[0mFreeVR Config[1m>>[0m[0m[0mMachine is vermeer[0m[0m
[0m[0mFreeVR config: [1mUsing system 'cave-dri'
[0m[0m[0mFreeVR Config[1m>>[0m[0m[0mdone testing if *******************************************[0m[0m
[0m[0mConfig Parse Warning (line 1022): [31mReplacing definition of input "visbox-fob::6sensor[head]".
[0m[0m[0mFreeVR Config[1m>>[0m[0m[0mConfig Parse (line 1408): [31mno such variable '$FVR_MONO'
[0m[0m[0m********************************* [0m[0m<nil>[0m[0m
[0m[0mConfig Parse (line 1409): [31mno such variable '$FVR_MONO'
[0m[0m[0mFreeVR config: Done Parsing "Config file: '/usr/local/freevr/.freevrrc'".  Read 2017 lines.
[0m[0mFreeVR config: [1mReading file "/home/phil/.freevrrc".
[0m[0m[0mFreeVR config: Done Parsing "Config file: '/home/phil/.freevrrc'".  Read 23 lines.
[0m[0mFreeVR config: [31mcould not open file "./.freevrrc".
[0m[0m[0m


config for window 0


[0m[0m[31mHEY, about to use dualeye_buffer! (0) -- this is where we should disable any visrenmode that assumes a stereo buffer if we didn't get one!
[0m[0mProcess name for stats on window 'front-magritte' is 'self'
[0m[0mProcess name for stats on window 'front-magritte' is 'main'
[0m[0mProcess name for stats on window 'front-magritte' is 'is900-input'
[0m[0m


config for window 1


[0m[0m[31mHEY, about to use dualeye_buffer! (0) -- this is where we should disable any visrenmode that assumes a stereo buffer if we didn't get one!
[0m[0m


config for window 2


[0m[0m[31mHEY, about to use dualeye_buffer! (0) -- this is where we should disable any visrenmode that assumes a stereo buffer if we didn't get one!
[0m[0m


config for window 3


[0m[0m[31mHEY, about to use dualeye_buffer! (0) -- this is where we should disable any visrenmode that assumes a stereo buffer if we didn't get one!
[0m[0m**************************************************
[0m[0mFreeVR Version 0.5g-beta
[0m[0mCompiled: Feb 27 2007 at 17:50:02 on vermeer (Linux 2.6.17-11-generic)[linux2.6-glx-64] with GLX
[0m[0mApplication name = (null)
[0m[0mApplication authors = (null)
[0m[0mApplication info = (null)
[0m[0mApplication status = (null)
[0m[0mHome directory = '/usr/local/freevr'
[0m[0mstatus = 'uninitialized' (-2)
[0m[0mstartup_error = 0x0
[0m[0mshmem_size = 536870912
[0m[0mcontext structure = 0x0x2aaaaab1f060
[0m[0mconfig structure = 0x0x2aaaaab2b7f0
[0m[0minput structure = 0x0x2aaaaab2b930
[0m[0mcallbacks structure = 0x0x2aaaaab29c00
[0m[0mobject_lists structure = 0x0x2aaaaab1f420
[0m[0mtime immemorial = 1201029117.30
[0m[0mpaused time = 0.00
[0m[0mpause w-time = -1.00
[0m[0mpaused? = 0
[0m[0m--------- current callback list:
[0m[0mCBlist = {
[0m[0m	VisrenInit = 0x0x2aaaaab29c30 (Default:VisrenInit-DN)
	VisrenFrame = 0x0x2aaaaab2a570 (Default:VisrenFrame-DN)
	VisrenWorld = 0x0x2aaaaab2aa10 (Default:VisrenWorld-NullWorld)
	VisrenSim = 0x0x2aaaaab2aeb0 (Default:VisrenSim-DefSim)
	VisrenExit = 0x0x2aaaaab2a0d0 (Default:VisrenExit-DN)
	HandleUSR2 = 0x0x2aaaaab2b350 (Default:HandleUSR2-DN)
[0m[0m}
[0m[0mLock list: head/lock = 0x0x2aaaaab1f220, tail = 0x0x2aaaaad771b0
[0m[0mLock values: semset = 0x83001b, semnum = 46
[0m[0mBarrier list: head = 0x(nil), tail = 0x(nil), lock = 0x0x2aaaaab1f2a0
[0m[0m**************************************************
[0mCAVE5D: attempting to allocate 6080 bytes from shared memory for data structure.
Cave5D: GL: direct connection = True
CAVE5D: using pthreads.

CAVE5D: config: reading config file cbay.tcl.
CAVE5D: config: ###############################################################################
CAVE5D: config: #
CAVE5D: config: #  Vis5D configuration
CAVE5D: config: #
CAVE5D: config: ###############################################################################
CAVE5D: config: 
CAVE5D: config: #
CAVE5D: config: # Display context stuff
CAVE5D: config: #
CAVE5D: config: 
CAVE5D: config: set idisp_ctx 0 ; # Display context index (Cave5D has only one)
CAVE5D: config: 
CAVE5D: config: # Load all of the data files first:
CAVE5D: config: #                              MBS FILE                 LABEL
CAVE5D: config: #vis5d_load_v5dfile $idisp_ctx 200 data/vis5d/LAMPS.v5d DataContext0
CAVE5D: config: 
CAVE5D: config: vis5d_load_v5dfile $idisp_ctx 500 cbay.v5d DataContext0
CAVE5D: config: 
CAVE5D: config: vis5d_init_path $idisp_ctx .
CAVE5D: config: vis5d_init_map $idisp_ctx OUTLUSAM
CAVE5D: config: set hires 0
CAVE5D: config: vis5d_init_topo $idisp_ctx cbay.topo $hires
Topo range is mostly < 0.0.  Using the "Ocean" color table.
CAVE5D: config: #vis5d_set_topo_hires_maxverts $idisp_ctx 100000
CAVE5D: config: #vis5d_init_texture $idisp_ctx data/camx_LA_xxx.rgb
CAVE5D: config: 
CAVE5D: config: # Get the data context grid dimensions.  Note that the display context
CAVE5D: config: # grid dimensions will be the same as those of the first data context.
CAVE5D: config: 
CAVE5D: config: set nrows [ vis5d_get_dtx_grid_rows $idisp_ctx ]
CAVE5D: config: set ncols [ vis5d_get_dtx_grid_columns $idisp_ctx ]
CAVE5D: config: set nlevs [ vis5d_get_dtx_grid_levels $idisp_ctx ]
CAVE5D: config: set r_min 0
CAVE5D: config: set r_max [ expr $nrows - 1.0 ]
CAVE5D: config: set r_mid [ expr $r_max / 2.0 ]
CAVE5D: config: set c_min 0
CAVE5D: config: set c_max [ expr $ncols - 1.0 ]
CAVE5D: config: set c_mid [ expr $c_max / 2.0 ]
CAVE5D: config: set l_min 0
CAVE5D: config: set l_max [ expr $nlevs - 1.0 ]
CAVE5D: config: set l_mid [ expr $l_max / 2.0 ]
CAVE5D: config: 
CAVE5D: config: 
CAVE5D: config: vis5d_set_color $idisp_ctx VIS5D_BOX 0 1.0 1.0 1.0 1.0
CAVE5D: config: 
CAVE5D: config: vis5d_graphics_mode $idisp_ctx VIS5D_TOPO VIS5D_ON
CAVE5D: config: 
CAVE5D: config: vis5d_set_topo_base $idisp_ctx 1 0.0
Topo range is mostly < 0.0.  Using the "Ocean" color table.
CAVE5D: config: #vis5d_set_vert_exaggeration $idisp_ctx 30
CAVE5D: config: 
CAVE5D: config: 
CAVE5D: config: #
CAVE5D: config: # Data context object stuff
CAVE5D: config: #
CAVE5D: config: # The default state of data context objects is "off".  If an object's
CAVE5D: config: # initial state is to be "on", an "enable_graphics" command is needed:
CAVE5D: config: #
CAVE5D: config: #     vis5d_enable_graphics $idata_ctx VIS5D_ISOSURF S VIS5D_ON
CAVE5D: config: #
CAVE5D: config: 
CAVE5D: config: set idata_ctx 0 ; # Data context index (Cave5D may have more than one)
CAVE5D: config: 
CAVE5D: config: # Wind Objects
CAVE5D: config: # Note that wind objects are tied to the _display_ context.
CAVE5D: config: 
CAVE5D: config: vis5d_set_wind_vars_and_owners $idisp_ctx				\
CAVE5D: config: 	$idata_ctx U $idata_ctx V $idata_ctx W				\
CAVE5D: config: 	$idata_ctx U $idata_ctx V $idata_ctx W				\
CAVE5D: config: 	$idata_ctx U $idata_ctx V $idata_ctx W
CAVE5D: config: 
CAVE5D: config: vis5d_set_hwindslice $idisp_ctx 0 0.5 20.0 $l_max
CAVE5D: config: vis5d_set_color $idisp_ctx VIS5D_HWIND 0 1.0 1.0 1.0 1.0
CAVE5D: config: 
CAVE5D: config: vis5d_set_vwindslice $idisp_ctx 0 1.0 20.0 $r_max 22.18 14.2 $c_max
CAVE5D: config: vis5d_set_color $idisp_ctx VIS5D_VWIND 0 0.0 1.0 1.0 1.0
CAVE5D: config: 
CAVE5D: config: #set lev [ expr ($l_mid + $l_min) / 2.0 ]
CAVE5D: config: #vis5d_set_hstreamslice $idisp_ctx 0 1.0 $lev
CAVE5D: config: 
CAVE5D: config: # Isosurfaces
CAVE5D: config: 
CAVE5D: config: vis5d_set_isosurface $idata_ctx FISH 3.0
CAVE5D: config: vis5d_set_color $idata_ctx VIS5D_ISOSURF FISH 1.0 1.0 0.0 1.0
CAVE5D: config: 
CAVE5D: config: vis5d_set_isosurface $idata_ctx SAL -4.0
CAVE5D: config: vis5d_set_color $idata_ctx VIS5D_ISOSURF SAL 1.0 0.5 1.0 1.0
CAVE5D: config: 
CAVE5D: config: # Colored slices
CAVE5D: config: 
CAVE5D: config: #set lev [ expr ($l_max + $l_mid) / 2.0 ]
CAVE5D: config: #vis5d_set_chslice $idata_ctx T $lev
CAVE5D: config: 
CAVE5D: config: #set lev [ expr ($l_min + $l_mid) / 2.0 ]
CAVE5D: config: #vis5d_make_clone_variable $idata_ctx T2 T
CAVE5D: config: #vis5d_set_chslice $idata_ctx T2 $lev
CAVE5D: config: 
CAVE5D: config: #vis5d_set_chslice $idata_ctx SPD $l_mid
CAVE5D: config: #vis5d_enable_graphics $idata_ctx VIS5D_CHSLICE SPD VIS5D_ON
CAVE5D: config: 
CAVE5D: config: #vis5d_set_cvslice $idata_ctx SPD $r_min $c_mid $r_max $c_mid
CAVE5D: config: 
CAVE5D: config: # Contoured slices
CAVE5D: config: 
CAVE5D: config: vis5d_set_hslice $idata_ctx SAL 1.0 -35.0 3.0 $l_max
CAVE5D: config: vis5d_set_color $idata_ctx VIS5D_HSLICE SAL 1.0 0.5 1.0 1.0
CAVE5D: config: 
CAVE5D: config: vis5d_set_vslice $idata_ctx SAL 0.5 -35.0 3.0 $r_mid 0 $r_mid $c_max
CAVE5D: config: vis5d_set_color $idata_ctx VIS5D_VSLICE SAL 1.0 0.5 1.0 1.0
CAVE5D: config: 
CAVE5D: config: # Volume visualizations
CAVE5D: config: #
CAVE5D: config: # Note that only one volume is visible at a time.  Therefore, a volume
CAVE5D: config: # needs to be "set" (vis5d_set_volume_and_owner $idisp_ctx $idata_ctx var)
CAVE5D: config: # only if it is to be displayed at startup.  Otherwise, the volume
CAVE5D: config: # is "set" when it is selected through the UI.
CAVE5D: config: 
CAVE5D: config: #vis5d_set_volume_and_owner $idisp_ctx $idata_ctx SPD
CAVE5D: config: #vis5d_set_volume_dims $idisp_ctx -100000 -1 -1
CAVE5D: config: 
CAVE5D: config: 
CAVE5D: config: 
CAVE5D: config: ###############################################################################
CAVE5D: config: #
CAVE5D: config: # Cave5D configuration
CAVE5D: config: #
CAVE5D: config: ###############################################################################
CAVE5D: config: 
CAVE5D: config: # Check to see if this script is running with Cave5D.  This check allows
CAVE5D: config: # the same configuration script to be used with Vis5D as well as Cave5D.
CAVE5D: config: 
CAVE5D: config: if { [ info commands cave5d* ] == "" } { return }
CAVE5D: config: 
CAVE5D: config: 
CAVE5D: config: #
CAVE5D: config: # Set Cave5D options
CAVE5D: config: #
CAVE5D: config: 
CAVE5D: config: cave5d_parm_set CLOCK_MODE		VIS5D
CAVE5D: config: cave5d_parm_set CLOCK_POSITION		-4.0 9.0 -5.0   -3.25 8.25 -5.0
CAVE5D: config: cave5d_parm_set ALL_PANELS_CONFIG	../config/panel.mini
CAVE5D: config: cave5d_parm_set INIT_POSITION 		0.0	5.0	-5.0
CAVE5D: config: cave5d_parm_set INIT_ROTATION		0.0	0.0	0.0
CAVE5D: config: cave5d_parm_set INIT_SCALE		4.5	4.5	4.5
CAVE5D: config: cave5d_parm_set NAV_SPEED		1.0
CAVE5D: config: cave5d_parm_set CHANGE_SCALE_FACTOR	1.0
CAVE5D: config: cave5d_parm_set TARGET_RATE		3.0
CAVE5D: config: 
CAVE5D: config: #
CAVE5D: config: # Specify user interface menu items
CAVE5D: config: #
CAVE5D: config: 
CAVE5D: config: # Syntax when there is only one data context:
CAVE5D: config: #                 MENU LABEL         OBJECT_TYPE   VAR
CAVE5D: config: #cave5d_menu_item GOBJ "Isosurf - SPD" VIS5D_ISOSURF SPD
CAVE5D: config: #
CAVE5D: config: # Syntax when there are more than one data contexts:
CAVE5D: config: #                 MENU LABEL         OBJECT_TYPE   VAR.CTX
CAVE5D: config: #cave5d_menu_item GOBJ "SPD Isosurf" VIS5D_ISOSURF SPD.1
CAVE5D: config: 
CAVE5D: config: cave5d_menu_item GOBJ "Topography" VIS5D_TOPO 0
CAVE5D: config: #cave5d_menu_item GOBJ "Map Vectors" VIS5D_MAP 0
CAVE5D: config: cave5d_menu_item GOBJ "H_Slice - Currents" VIS5D_HWIND 0
CAVE5D: config: cave5d_menu_item GOBJ "V_Slice - Currents" VIS5D_VWIND 0
CAVE5D: config: cave5d_menu_item GOBJ "H_Contours - SAL" VIS5D_HSLICE SAL
CAVE5D: config: cave5d_menu_item GOBJ "V_Contours - SAL" VIS5D_VSLICE SAL
CAVE5D: config: cave5d_menu_item GOBJ "Isosurf - SAL" VIS5D_ISOSURF SAL
CAVE5D: config: cave5d_menu_item GOBJ "Isosurf - FISH" VIS5D_ISOSURF FISH
CAVE5D: config: #cave5d_menu_item GOBJ "VolViz - SPD" VIS5D_VOLUME SPD
CAVE5D: config: finished reading config file.

CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
CAVE5D: panel: processing configuration file ../config/panel.mini
adding dtx to ctx 0 0 0xaad7e440
Topo file EARTH.TOPO not found
Map file OUTLSUPW not found
Cache size: 585 grids 117 5
Reading all grids.
Topo file EARTH.TOPO not found
Map file OUTLSUPW not found
Map file ./OUTLUSAM not found
Map file ./OUTLUSAM not found
C5D memory size: 30
NavSpeed: 1.000000
Initial Position: 0.000000 5.000000 -5.000000
Initial Rotation: 0.000000 0.000000 0.000000
Initial Scale: 4.500000 4.500000 4.500000
Graphical Objects: 7
	Topography
	H_Slice - Currents
	V_Slice - Currents
	H_Contours - SAL
	V_Contours - SAL
	Isosurf - SAL
	Isosurf - FISH
Vis5D clock 
[0mFreeVR: [1m**** Initializing the System! ****
[0m[0m[34mFreeVR: Process "magritte-visren1" spawned!  Pid = 19688, time = 0.775631
[0m[34m_ProcessInitChild(): [31mNo process locking command available
[0m[32mFreeVR: Process "magritte-visren2" spawned!  Pid = 19689, time = 0.778985
[0m[32m_ProcessInitChild(): [31mNo process locking command available
[0m[33mFreeVR: Process "magritte-visren3" spawned!  Pid = 19690, time = 0.781350
[0m[33m_ProcessInitChild(): [31mNo process locking command available
[0m[36mFreeVR: Process "magritte-visren4" spawned!  Pid = 19691, time = 0.783505
[0m[36m_ProcessInitChild(): [31mNo process locking command available
[0m[32mFreeVR: Process "default-telnet" spawned!  Pid = 19692, time = 0.786146
[0m[32m_ProcessInitChild(): [31mNo process locking command available
[0m[35mFreeVR: Process "is900-input" spawned!  Pid = 19693, time = 0.788314
[0m[35m_ProcessInitChild(): [31mNo process locking command available
[0m[0mFreeVR: Inputs for device 'xwin-vr' are created.
[0m[0mFreeVR: Inputs for device 'is900-default' are created.
[0m[0mFreeVR: Inputs for device 'static-default' are [31mNOT YET created.[0m
[0m[0mFreeVR: [1mStill waiting for 'static-default' inputs to be created.
[0m[0m[0mFreeVR: [1m>>>>>>>>>>>>>> Inputs for all 3 devices created. <<<<<<<<<<<<<<
[0m[0m[0mvrUserInitialize(): [31mHardwire of [1mvrConfig->users[0]->head = 0x0x2aaac71db840
[0m[0m[0m**************************************************
[0m[0mFreeVR Version 0.5g-beta
[0m[0mCompiled: Feb 27 2007 at 17:50:02 on vermeer (Linux 2.6.17-11-generic)[linux2.6-glx-64] with GLX
[0m[0mApplication name = (null)
[0m[0mApplication authors = (null)
[0m[0mApplication info = (null)
[0m[0mApplication status = (null)
[0m[0mHome directory = '/usr/local/freevr'
[0m[0mstatus = 'initializing' (-1)
[0m[0mstartup_error = 0x0
[0m[0mshmem_size = 536870912
[0m[0mcontext structure = 0x0x2aaaaab1f060
[0m[0mconfig structure = 0x0x2aaaaab2b7f0
[0m[0minput structure = 0x0x2aaaaab2b930
[0m[0mcallbacks structure = 0x0x2aaaaab29c00
[0m[0mobject_lists structure = 0x0x2aaaaab1f420
[0m[0mtime immemorial = 1201029117.30
[0m[0mpaused time = 0.00
[0m[0mpause w-time = -1.00
[0m[0mpaused? = 0
[0m[0m--------- current callback list:
[0m[0mCBlist = {
[0m[0m	VisrenInit = 0x0x2aaaaab29c30 (Default:VisrenInit-DN)
	VisrenFrame = 0x0x2aaaaab2a570 (Default:VisrenFrame-DN)
	VisrenWorld = 0x0x2aaaaab2aa10 (Default:VisrenWorld-NullWorld)
	VisrenSim = 0x0x2aaaaab2aeb0 (Default:VisrenSim-DefSim)
	VisrenExit = 0x0x2aaaaab2a0d0 (Default:VisrenExit-DN)
	HandleUSR2 = 0x0x2aaaaab2b350 (Default:HandleUSR2-DN)
[0m[0m}
[0m[0mLock list: head/lock = 0x0x2aaaaab1f220, tail = 0x0x2aaac71de620
[0m[0mLock values: semset = 0x83001b, semnum = 136
[0m[0mBarrier list: head = 0x(nil), tail = 0x(nil), lock = 0x0x2aaaaab1f2a0
[0m[0m**************************************************
[0m[0m==================================================
[0m[0mUsing System = [1m"cave-dri"[0m (init = 0)
[0m[0mdebug level = 10
[0m[0mdebug exact = 0
[0m[0mvisrenmode default = "dualfb" (4)
[0m[0mprocessor lock default = "TODO:" (1)
[0m[0mInputMap = "default"
[0m[0m3 input devs = [ [0m[0m"xwin-vr" [0m[0m"is900-default" [0m[0m"static-default" [0m[0m] (init = 1)
[0m[0m1 props = [ [0m[0m"default" [0m[0m] (init = NYI)
[0m[0m1 users = [ [0m[0m"default" [0m[0m] (init = 1)
[0m[0m2 eyes = [ [0m[0m"default:lefteye" [0m[0m"default:righteye" [0m[0m]
[0m[0m1 eyelists = [ [0m[0m"default" [0m[0m]
[0m[0m4 windows = [ [0m[0m"front-magritte" [0m[0m"left-magritte" [0m[0m"right-magritte" [0m[0m"floor-magritte" [0m[0m] (init = NYI)
[0m[0m7 processes = [ [0m[0m"built-in main" (19686) [0m[0m"magritte-visren1" (19688) [0m[0m"magritte-visren2" (19689) [0m[0m"magritte-visren3" (19690) [0m[0m"magritte-visren4" (19691) [0m[0m"default-telnet" (19692) [0m[0m"is900-input" (19693) [0m[0m]
[0m[0m==================================================
[0m[0mFreeVR: [1m**** FreeVR library startup complete. ****
[0m[0mCAVE5D: event loop: begin
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
ui_event -- state = 0   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.074164 0.020833 -0.034165
### move: 0.020833 0.074164 -0.034165
### move: 0.074164   0.000000 0.074164 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.114162 0.037498 0.009167
### move: 0.037498 0.114162 0.009167
### move: 0.114162   0.000000 0.114162 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.017499 0.019166 0.022499
### move: 0.019166 0.017499 0.022499
### move: 0.022499   0.000000 0.000000 0.022499
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.002500 0.014999 0.000833
### move: 0.014999 0.002500 0.000833
### move: 0.014999   0.014999 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.054998 0.014166 -0.065831
### move: 0.014166 -0.054998 -0.065831
### move: 0.065831   0.000000 0.000000 -0.065831
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> move: check sync
>>> move: -0.018332 0.018333 -0.061664
### move: 0.018333 -0.018332 -0.061664
### move: 0.061664   0.000000 0.000000 -0.061664
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
ui_event -- state = 1   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
state = 1
gobj_modify: turning on: >H_Slice - Currents< >< 0 6 -1
...make hwind 0 -1
gobj_make: done
ui_event -- state = 1   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
state = 2
gobj_modify: moveable: >H_Slice - Currents< >< 0 6 -1
ui_event -- state = 1   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
ui_event -- state = 1   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
ui_event -- state = 1   amgr = 0x2aaaaad7c980
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: -0.003333 -0.004167 -0.001667
### move: -0.004167 -0.003333 -0.001667
### move: 0.004167   -0.004167 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000833 -0.001667 -0.007499
### move: -0.001667 0.000833 -0.007499
### move: 0.007499   0.000000 0.000000 -0.007499
### move: old lev: 12.000000
### new_lev: 12.000000 -0.007499 0.000000
### new_lev: 11.700022
### new_lev: 11.700022 done
### move: new lev: 11.700022
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 -0.004167 -0.004167
### move: -0.004167 0.000000 -0.004167
### move: 0.004167   -0.004167 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.004166 0.002500 -0.014166
### move: 0.002500 -0.004166 -0.014166
### move: 0.014166   0.000000 0.000000 -0.014166
### move: old lev: 11.700022
### new_lev: 11.700022 -0.014166 0.000000
### new_lev: 11.133389
### new_lev: 11.133389 done
### move: new lev: 11.133389
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.002500 -0.013333
### move: 0.002500 0.000000 -0.013333
### move: 0.013333   0.000000 0.000000 -0.013333
### move: old lev: 11.133389
### new_lev: 11.133389 -0.013333 0.000000
### new_lev: 10.600058
### new_lev: 10.600058 done
### move: new lev: 10.600058
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.007500 -0.015833
### move: 0.007500 0.000000 -0.015833
### move: 0.015833   0.000000 0.000000 -0.015833
### move: old lev: 10.600058
### new_lev: 10.600058 -0.015833 0.000000
### new_lev: 9.966756
### new_lev: 9.966756 done
### move: new lev: 9.966756
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> move: 0.000000 0.013333 -0.034165
### move: 0.013333 0.000000 -0.034165
### move: 0.034165   0.000000 0.000000 -0.034165
### move: old lev: 9.966756
### new_lev: 9.966756 -0.034165 0.000000
### new_lev: 8.600138
### new_lev: 8.600138 done
### move: new lev: 8.600138
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.007500 -0.015833
### move: 0.007500 0.000000 -0.015833
### move: 0.015833   0.000000 0.000000 -0.015833
### move: old lev: 8.600138
### new_lev: 8.600138 -0.015833 0.000000
### new_lev: 7.966836
### new_lev: 7.966836 done
### move: new lev: 7.966836
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.019166 -0.039165
### move: 0.019166 0.000000 -0.039165
### move: 0.039165   0.000000 0.000000 -0.039165
### move: old lev: 7.966836
### new_lev: 7.966836 -0.039165 0.000000
### new_lev: 6.400233
### new_lev: 6.400233 done
### move: new lev: 6.400233
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
move: 0.000000 0.026665 -0.065831
### move: 0.026665 0.000000 -0.065831
### move: 0.065831   0.000000 0.000000 -0.065831
### move: old lev: 6.400233
### new_lev: 6.400233 -0.065831 0.000000
### new_lev: 3.766990
### new_lev: 3.766990 done
### move: new lev: 3.766990
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.006667 -0.023332
### move: 0.006667 0.000000 -0.023332
### move: 0.023332   0.000000 0.000000 -0.023332
### move: old lev: 3.766990
### new_lev: 3.766990 -0.023332 0.000000
### new_lev: 2.833710
### new_lev: 2.833710 done
### move: new lev: 2.833710
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000833 0.010833 -0.038332
### move: 0.010833 0.000833 -0.038332
### move: 0.038332   0.000000 0.000000 -0.038332
### move: old lev: 2.833710
### new_lev: 2.833710 -0.038332 0.000000
### new_lev: 1.300431
### new_lev: 1.300431 done
### move: new lev: 1.300431
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000833 0.019999 -0.082497
### move: 0.019999 0.000833 -0.082497
### move: 0.082497   0.000000 0.000000 -0.082497
### move: old lev: 1.300431
### new_lev: 1.300431 -0.082497 0.000000
### new_lev: -1.999437
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000833 0.011666 -0.042498
### move: 0.011666 0.000833 -0.042498
### move: 0.042498   0.000000 0.000000 -0.042498
### move: old lev: 0.000000
### new_lev: 0.000000 -0.042498 0.000000
### new_lev: -1.699920
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.008333 0.005833 -0.046665
### move: 0.005833 -0.008333 -0.046665
### move: 0.046665   0.000000 0.000000 -0.046665
### move: old lev: 0.000000
### new_lev: 0.000000 -0.046665 0.000000
### new_lev: -1.866603
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.001667 0.000833 -0.022499
### move: 0.000833 0.001667 -0.022499
### move: 0.022499   0.000000 0.000000 -0.022499
### move: old lev: 0.000000
### new_lev: 0.000000 -0.022499 0.000000
### new_lev: -0.899956
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000833 0.003333 -0.023333
### move: 0.003333 0.000833 -0.023333
### move: 0.023333   0.000000 0.000000 -0.023333
### move: old lev: 0.000000
### new_lev: 0.000000 -0.023333 0.000000
### new_lev: -0.933301
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000833 0.005000 -0.005833
### move: 0.005000 0.000833 -0.005833
### move: 0.005833   0.000000 0.000000 -0.005833
### move: old lev: 0.000000
### new_lev: 0.000000 -0.005833 0.000000
### new_lev: -0.233331
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
>>> frame: pid = 19689
gobj_make: done
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: -0.002500 0.002500 0.000834
### move: 0.002500 -0.002500 0.000834
### move: 0.002500   0.000000 -0.002500 0.000000
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.001667 0.003333 0.018332
### move: 0.003333 -0.001667 0.018332
### move: 0.018332   0.000000 0.000000 0.018332
### move: old lev: 0.000000
### new_lev: 0.000000 0.018332 0.000000
### new_lev: 0.733294
### new_lev: 0.733294 done
### move: new lev: 0.733294
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: -0.001667 0.000833 0.016666
### move: 0.000833 -0.001667 0.016666
### move: 0.016666   0.000000 0.000000 0.016666
### move: old lev: 0.733294
### new_lev: 0.733294 0.016666 0.000000
### new_lev: 1.399941
### new_lev: 1.399941 done
### move: new lev: 1.399941
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.000833 0.000000 0.035832
### move: 0.000000 -0.000833 0.035832
### move: 0.035832   0.000000 0.000000 0.035832
### move: old lev: 1.399941
### new_lev: 1.399941 0.035832 0.000000
### new_lev: 2.833207
### new_lev: 2.833207 done
### move: new lev: 2.833207
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: -0.000833 -0.000833 0.027499
### move: -0.000833 -0.000833 0.027499
### move: 0.027499   0.000000 0.000000 0.027499
### move: old lev: 2.833207
### new_lev: 2.833207 0.027499 0.000000
### new_lev: 3.933170
### new_lev: 3.933170 done
### move: new lev: 3.933170
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.000833 0.000000 0.040832
### move: 0.000000 -0.000833 0.040832
### move: 0.040832   0.000000 0.000000 0.040832
### move: old lev: 3.933170
### new_lev: 3.933170 0.040832 0.000000
### new_lev: 5.566442
### new_lev: 5.566442 done
### move: new lev: 5.566442
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.006666 0.000000 0.038331
### move: 0.000000 0.006666 0.038331
### move: 0.038331   0.000000 0.000000 0.038331
### move: old lev: 5.566442
### new_lev: 5.566442 0.038331 0.000000
### new_lev: 7.099700
### new_lev: 7.099700 done
### move: new lev: 7.099700
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.001667 0.005000 0.030833
### move: 0.005000 0.001667 0.030833
### move: 0.030833   0.000000 0.000000 0.030833
### move: old lev: 7.099700
### new_lev: 7.099700 0.030833 0.000000
### new_lev: 8.333001
### new_lev: 8.333001 done
### move: new lev: 8.333001
### move: make -1 0
...make hwind 0 -1
>>> display: pid = 19689
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.001667 0.008333 0.035832
### move: 0.008333 0.001667 0.035832
### move: 0.035832   0.000000 0.000000 0.035832
### move: old lev: 8.333001
### new_lev: 8.333001 0.035832 0.000000
### new_lev: 9.766266
### new_lev: 9.766266 done
### move: new lev: 9.766266
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: -0.000833 0.019166 0.050831
### move: 0.019166 -0.000833 0.050831
### move: 0.050831   0.000000 0.000000 0.050831
### move: old lev: 9.766266
### new_lev: 9.766266 0.050831 0.000000
### new_lev: 11.799509
### new_lev: 11.799509 done
### move: new lev: 11.799509
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.009166 0.021666 0.044165
### move: 0.021666 0.009166 0.044165
### move: 0.044165   0.000000 0.000000 0.044165
### move: old lev: 11.799509
### new_lev: 11.799509 0.044165 0.000000
### new_lev: 13.566119
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.004167 0.017499 0.045831
### move: 0.017499 0.004167 0.045831
### move: 0.045831   0.000000 0.000000 0.045831
### move: old lev: 12.000000
### new_lev: 12.000000 0.045831 0.000000
### new_lev: 13.833258
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> move: -0.000833 0.005000 0.013333
### move: 0.005000 -0.000833 0.013333
### move: 0.013333   0.000000 0.000000 0.013333
### move: old lev: 12.000000
### new_lev: 12.000000 0.013333 0.000000
### new_lev: 12.533309
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.005000 0.009167 0.028332
### move: 0.009167 0.005000 0.028332
### move: 0.028332   0.000000 0.000000 0.028332
### move: old lev: 12.000000
### new_lev: 12.000000 0.028332 0.000000
### new_lev: 13.133287
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.002500 0.007500 0.024166
### move: 0.007500 0.002500 0.024166
### move: 0.024166   0.000000 0.000000 0.024166
### move: old lev: 12.000000
### new_lev: 12.000000 0.024166 0.000000
### new_lev: 12.966625
### new_lev: 12.000000 done
>>> display: pid = 19690
gobj_make: done
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.004167 0.005000 0.019166
### move: 0.005000 0.004167 0.019166
### move: 0.019166   0.000000 0.000000 0.019166
### move: old lev: 12.000000
### new_lev: 12.000000 0.019166 0.000000
### new_lev: 12.766640
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.004166 0.004166 0.020833
### move: 0.004166 0.004166 0.020833
### move: 0.020833   0.000000 0.000000 0.020833
### move: old lev: 12.000000
### new_lev: 12.000000 0.020833 0.000000
### new_lev: 12.833309
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.005000 0.007500 0.036665
### move: 0.007500 0.005000 0.036665
### move: 0.036665   0.000000 0.000000 0.036665
### move: old lev: 12.000000
### new_lev: 12.000000 0.036665 0.000000
### new_lev: 13.466589
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.000833 0.007500 0.016666
### move: 0.007500 -0.000833 0.016666
### move: 0.016666   0.000000 0.000000 0.016666
### move: old lev: 12.000000
### new_lev: 12.000000 0.016666 0.000000
### new_lev: 12.666647
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> move: check sync
>>> move: -0.000833 0.005833 0.010833
### move: 0.005833 -0.000833 0.010833
### move: 0.010833   0.000000 0.000000 0.010833
### move: old lev: 12.000000
### new_lev: 12.000000 0.010833 0.000000
### new_lev: 12.433316
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.000833 0.006667 0.005833
### move: 0.006667 -0.000833 0.005833
### move: 0.006667   0.006667 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.005000 0.000000
### move: 0.005000 0.000000 0.000000
### move: 0.005000   0.005000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000833 -0.029999
### move: 0.000833 0.000000 -0.029999
### move: 0.029999   0.000000 0.000000 -0.029999
### move: old lev: 12.000000
### new_lev: 12.000000 -0.029999 0.000000
### new_lev: 10.800044
### new_lev: 10.800044 done
### move: new lev: 10.800044
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000833 0.000833 -0.021666
### move: 0.000833 0.000833 -0.021666
### move: 0.021666   0.000000 0.000000 -0.021666
### move: old lev: 10.800044
### new_lev: 10.800044 -0.021666 0.000000
### new_lev: 9.933412
### new_lev: 9.933412 done
### move: new lev: 9.933412
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 -0.001666 -0.021666
### move: -0.001666 0.000000 -0.021666
### move: 0.021666   0.000000 0.000000 -0.021666
### move: old lev: 9.933412
### new_lev: 9.933412 -0.021666 0.000000
### new_lev: 9.066779
### new_lev: 9.066779 done
### move: new lev: 9.066779
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.001666 -0.006667 -0.031666
### move: -0.006667 0.001666 -0.031666
### move: 0.031666   0.000000 0.000000 -0.031666
### move: old lev: 9.066779
### new_lev: 9.066779 -0.031666 0.000000
### new_lev: 7.800154
### new_lev: 7.800154 done
### move: new lev: 7.800154
### move: make -1 0
...make hwind 0 -1
>>> display: pid = 19691
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.003333 -0.005833 -0.044998
### move: -0.005833 0.003333 -0.044998
### move: 0.044998   0.000000 0.000000 -0.044998
### move: old lev: 7.800154
### new_lev: 7.800154 -0.044998 0.000000
### new_lev: 6.000242
### new_lev: 6.000242 done
### move: new lev: 6.000242
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 -0.002500 -0.021666
### move: -0.002500 0.000000 -0.021666
### move: 0.021666   0.000000 0.000000 -0.021666
### move: old lev: 6.000242
### new_lev: 6.000242 -0.021666 0.000000
### new_lev: 5.133609
### new_lev: 5.133609 done
### move: new lev: 5.133609
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.004166 -0.006667 -0.028332
### move: -0.006667 0.004166 -0.028332
### move: 0.028332   0.000000 0.000000 -0.028332
### move: old lev: 5.133609
### new_lev: 5.133609 -0.028332 0.000000
### new_lev: 4.000322
### new_lev: 4.000322 done
### move: new lev: 4.000322
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: 0.005000 -0.008333 -0.024166
### move: -0.008333 0.005000 -0.024166
### move: 0.024166   0.000000 0.000000 -0.024166
### move: old lev: 4.000322
### new_lev: 4.000322 -0.024166 0.000000
### new_lev: 3.033697
### new_lev: 3.033697 done
### move: new lev: 3.033697
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000833 -0.010000 -0.024999
### move: -0.010000 0.000833 -0.024999
### move: 0.024999   0.000000 0.000000 -0.024999
### move: old lev: 3.033697
### new_lev: 3.033697 -0.024999 0.000000
### new_lev: 2.033727
### new_lev: 2.033727 done
### move: new lev: 2.033727
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.005000 -0.008333 -0.024166
### move: -0.008333 0.005000 -0.024166
### move: 0.024166   0.000000 0.000000 -0.024166
### move: old lev: 2.033727
### new_lev: 2.033727 -0.024166 0.000000
### new_lev: 1.067101
### new_lev: 1.067101 done
### move: new lev: 1.067101
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.006666 -0.012500 -0.029999
### move: -0.012500 0.006666 -0.029999
### move: 0.029999   0.000000 0.000000 -0.029999
### move: old lev: 1.067101
### new_lev: 1.067101 -0.029999 0.000000
### new_lev: -0.132854
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000833 -0.011666 -0.028332
### move: -0.011666 0.000833 -0.028332
### move: 0.028332   0.000000 0.000000 -0.028332
### move: old lev: 0.000000
### new_lev: 0.000000 -0.028332 0.000000
### new_lev: -1.133287
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
>>> display: pid = 19689
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000833 -0.014999 -0.018332
### move: -0.014999 0.000833 -0.018332
### move: 0.018332   0.000000 0.000000 -0.018332
### move: old lev: 0.000000
### new_lev: 0.000000 -0.018332 0.000000
### new_lev: -0.733294
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000833 -0.013333 -0.018333
### move: -0.013333 0.000833 -0.018333
### move: 0.018333   0.000000 0.000000 -0.018333
### move: old lev: 0.000000
### new_lev: 0.000000 -0.018333 0.000000
### new_lev: -0.733316
### new_lev: 0.000000 done
### move: new lev: 0.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.001667 -0.013333 -0.011666
### move: -0.013333 0.001667 -0.011666
### move: 0.013333   -0.013333 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 -0.005000 0.000000
### move: -0.005000 0.000000 0.000000
### move: 0.005000   -0.005000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: -0.005000 0.000000 0.001667
### move: 0.000000 -0.005000 0.001667
### move: 0.005000   0.000000 -0.005000 0.000000
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.009166 0.000833 0.008333
### move: 0.000833 -0.009166 0.008333
### move: 0.009166   0.000000 -0.009166 0.000000
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> move: -0.002500 0.004167 0.017500
### move: 0.004167 -0.002500 0.017500
### move: 0.017500   0.000000 0.000000 0.017500
### move: old lev: 0.000000
### new_lev: 0.000000 0.017500 0.000000
### new_lev: 0.699992
### new_lev: 0.699992 done
### move: new lev: 0.699992
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: -0.004167 0.010833 0.026665
### move: 0.010833 -0.004167 0.026665
### move: 0.026665   0.000000 0.000000 0.026665
### move: old lev: 0.699992
### new_lev: 0.699992 0.026665 0.000000
### new_lev: 1.766610
### new_lev: 1.766610 done
### move: new lev: 1.766610
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.006666 0.018333 0.042499
### move: 0.018333 -0.006666 0.042499
### move: 0.042499   0.000000 0.000000 0.042499
### move: old lev: 1.766610
### new_lev: 1.766610 0.042499 0.000000
### new_lev: 3.466551
### new_lev: 3.466551 done
### move: new lev: 3.466551
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: -0.000833 0.012499 0.024999
### move: 0.012499 -0.000833 0.024999
### move: 0.024999   0.000000 0.000000 0.024999
### move: old lev: 3.466551
### new_lev: 3.466551 0.024999 0.000000
### new_lev: 4.466500
### new_lev: 4.466500 done
### move: new lev: 4.466500
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> move: -0.009166 0.015833 0.023333
### move: 0.015833 -0.009166 0.023333
### move: 0.023333   0.000000 0.000000 0.023333
### move: old lev: 4.466500
### new_lev: 4.466500 0.023333 0.000000
### new_lev: 5.399802
### new_lev: 5.399802 done
### move: new lev: 5.399802
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.009166 0.012499 0.018332
### move: 0.012499 -0.009166 0.018332
### move: 0.018332   0.000000 0.000000 0.018332
### move: old lev: 5.399802
### new_lev: 5.399802 0.018332 0.000000
### new_lev: 6.133096
### new_lev: 6.133096 done
### move: new lev: 6.133096
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.002500 0.016666 0.033332
### move: 0.016666 -0.002500 0.033332
### move: 0.033332   0.000000 0.000000 0.033332
### move: old lev: 6.133096
### new_lev: 6.133096 0.033332 0.000000
### new_lev: 7.466390
### new_lev: 7.466390 done
### move: new lev: 7.466390
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19689
>>> move: check sync
>>> move: -0.002500 0.010833 0.024166
### move: 0.010833 -0.002500 0.024166
### move: 0.024166   0.000000 0.000000 0.024166
### move: old lev: 7.466390
### new_lev: 7.466390 0.024166 0.000000
### new_lev: 8.433016
### new_lev: 8.433016 done
### move: new lev: 8.433016
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> move: -0.001667 0.006666 0.018332
### move: 0.006666 -0.001667 0.018332
### move: 0.018332   0.000000 0.000000 0.018332
### move: old lev: 8.433016
### new_lev: 8.433016 0.018332 0.000000
### new_lev: 9.166310
### new_lev: 9.166310 done
### move: new lev: 9.166310
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> move: check sync
>>> move: -0.001666 0.005833 0.014999
### move: 0.005833 -0.001666 0.014999
### move: 0.014999   0.000000 0.000000 0.014999
### move: old lev: 9.166310
### new_lev: 9.166310 0.014999 0.000000
### new_lev: 9.766289
### new_lev: 9.766289 done
### move: new lev: 9.766289
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.006667 0.018332
### move: 0.006667 0.000000 0.018332
### move: 0.018332   0.000000 0.000000 0.018332
### move: old lev: 9.766289
### new_lev: 9.766289 0.018332 0.000000
### new_lev: 10.499583
### new_lev: 10.499583 done
### move: new lev: 10.499583
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19688
>>> move: check sync
>>> move: -0.000833 0.005833 0.014166
### move: 0.005833 -0.000833 0.014166
### move: 0.014166   0.000000 0.000000 0.014166
### move: old lev: 10.499583
### new_lev: 10.499583 0.014166 0.000000
### new_lev: 11.066237
### new_lev: 11.066237 done
### move: new lev: 11.066237
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.001667 0.003333 0.014999
### move: 0.003333 0.001667 0.014999
### move: 0.014999   0.000000 0.000000 0.014999
### move: old lev: 11.066237
### new_lev: 11.066237 0.014999 0.000000
### new_lev: 11.666216
### new_lev: 11.666216 done
### move: new lev: 11.666216
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> frame: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> move: 0.009166 0.005000 0.017499
### move: 0.005000 0.009166 0.017499
### move: 0.017499   0.000000 0.000000 0.017499
### move: old lev: 11.666216
### new_lev: 11.666216 0.017499 0.000000
### new_lev: 12.366186
### new_lev: 12.000000 done
### move: new lev: 12.000000
### move: make -1 0
...make hwind 0 -1
gobj_make: done
>>> frame: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> move: 0.000000 0.000000 0.000000
### move: 0.000000 0.000000 0.000000
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19690
>>> display: pid = 19691
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19689
>>> display: pid = 19690
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19688
>>> move: check sync
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19688
>>> frame: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> frame: pid = 19691
>>> move: check sync
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19689
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19689
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19689
>>> display: pid = 19691
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> display: pid = 19688
>>> move: check sync
>>> frame: pid = 19691
>>> frame: pid = 19689
>>> display: pid = 19691
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19691
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19688
>>> frame: pid = 19691
>>> display: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> frame: pid = 19689
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> frame: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19689
>>> frame: pid = 19690
>>> move: check sync
>>> display: pid = 19690
>>> frame: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19689
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19688
>>> frame: pid = 19689
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19690
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19690
>>> display: pid = 19689
>>> display: pid = 19688
>>> move: check sync
>>> display: pid = 19691
>>> move: check sync
>>> display: pid = 19690
>>> display: pid = 19689
>>> move: check sync
>>> frame: pid = 19691
>>> display: pid = 19691
>>> frame: pid = 19688
>>> display: pid = 19689
ui_event -- state = -1   amgr = 0x2aaaaad7c980
CAVE5D: event loop: done
waiting for 5 processes to end
waiting for 2 processes to end
waiting for 2 processes to end
waiting for 2 processes to end
waiting for 2 processes to end
tired of waiting
Terminating Vis5D
!!!! Vis5d terminated
Terminating VR lib
[0mFreeVR: [1mFreeVR library terminating from a call to vrExit().
[0m[0m[35mFreeVR: Input Main Loop has ended -- [31mexiting process "is900-input".
[0m[0m[36mFreeVR: Visren Main Loop has ended -- [31mexiting process "magritte-visren4".
[0m[0m[36m_ProcessInitChild(): [31mNo process unlocking command available
[0m[33mFreeVR: Visren Main Loop has ended -- [31mexiting process "magritte-visren3".
[0m[0m[33m_ProcessInitChild(): [31mNo process unlocking command available
[0m[34mFreeVR: Visren Main Loop has ended -- [31mexiting process "magritte-visren1".
[0m[0m[34m_ProcessInitChild(): [31mNo process unlocking command available
[0m[32mFreeVR: Telnet Main Loop has ended -- [31mexiting process "default-telnet".
[0m[0m[32m_ProcessInitChild(): [31mNo process unlocking command available
[0m[32mFreeVR (telnet): Connect to 'vermeer:3000' to send commands to FreeVR
[0m[32m_GlxOpenFunc(): [31mdualeye_buffer = 0, visrenmode = 'dualfb' (4)
[0m[0m[32m[31mHEY, this is where dualeye_buffer gets set (1)
[0m[32mabout to create the icon pixmap for window 'left-magritte'
[0m[32mfinished creating the icon pixmap for window 'left-magritte' -- pixmap = 46137350
[0m[32mnow finished creating the cursor for window 'left-magritte' -- cursor = 46137354
[0m[32mFYI: vrCallbackUpdate(0x0x2aaaaab29c30, 0x0x2aaac71e9df0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[32mHEY, just set visreninit to 1 in callback updates section
[0m[32mFYI: vrCallbackUpdate(0x0x2aaaaab2a570, 0x0x2aaac71ea2a0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[32mFYI: vrCallbackUpdate(0x0x2aaaaab2aa10, 0x0x2aaac71ea750) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[32m_GlxRenderFunc(): [31mcall_visreninit was set to 1 for window 'left-magritte'
[0m[0m[34m_GlxOpenFunc(): [31mdualeye_buffer = 0, visrenmode = 'dualfb' (4)
[0m[0m[34m[31mHEY, this is where dualeye_buffer gets set (1)
[0m[34mabout to create the icon pixmap for window 'front-magritte'
[0m[34mfinished creating the icon pixmap for window 'front-magritte' -- pixmap = 41943046
[0m[34mnow finished creating the cursor for window 'front-magritte' -- cursor = 41943050
[0m[34mFYI: vrCallbackUpdate(0x0x2aaaaab29c30, 0x0x2aaac71e9df0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[34mHEY, just set visreninit to 1 in callback updates section
[0m[34mFYI: vrCallbackUpdate(0x0x2aaaaab2a570, 0x0x2aaac71ea2a0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[34mFYI: vrCallbackUpdate(0x0x2aaaaab2aa10, 0x0x2aaac71ea750) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[34m_GlxRenderFunc(): [31mcall_visreninit was set to 1 for window 'front-magritte'
[0m[0m[36m_GlxOpenFunc(): [31mdualeye_buffer = 0, visrenmode = 'dualfb' (4)
[0m[0m[36m[31mHEY, this is where dualeye_buffer gets set (1)
[0m[36mabout to create the icon pixmap for window 'floor-magritte'
[0m[36mfinished creating the icon pixmap for window 'floor-magritte' -- pixmap = 50331654
[0m[36mnow finished creating the cursor for window 'floor-magritte' -- cursor = 50331658
[0m[36mFYI: vrCallbackUpdate(0x0x2aaaaab29c30, 0x0x2aaac71e9df0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[36mHEY, just set visreninit to 1 in callback updates section
[0m[36mFYI: vrCallbackUpdate(0x0x2aaaaab2a570, 0x0x2aaac71ea2a0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[36mFYI: vrCallbackUpdate(0x0x2aaaaab2aa10, 0x0x2aaac71ea750) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[36m_GlxRenderFunc(): [31mcall_visreninit was set to 1 for window 'floor-magritte'
[0m[0m[33m_GlxOpenFunc(): [31mdualeye_buffer = 0, visrenmode = 'dualfb' (4)
[0m[0m[33m[31mHEY, this is where dualeye_buffer gets set (1)
[0m[33mabout to create the icon pixmap for window 'right-magritte'
[0m[33mfinished creating the icon pixmap for window 'right-magritte' -- pixmap = 48234502
[0m[33mnow finished creating the cursor for window 'right-magritte' -- cursor = 48234506
[0m[33mFYI: vrCallbackUpdate(0x0x2aaaaab29c30, 0x0x2aaac71e9df0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[33mHEY, just set visreninit to 1 in callback updates section
[0m[33mFYI: vrCallbackUpdate(0x0x2aaaaab2a570, 0x0x2aaac71ea2a0) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[33mFYI: vrCallbackUpdate(0x0x2aaaaab2aa10, 0x0x2aaac71ea750) called, orig cb = 0x(nil), new cb = 0x(nil)
[0m[33m_GlxRenderFunc(): [31mcall_visreninit was set to 1 for window 'right-magritte'
[0m[0m[35m_ProcessInitChild(): [31mNo process unlocking command available
[0m[35mchecking if 'fore' matches with 'fore' giving a value of 14
[0m[35mFreeVR: X11 input device xwin-vr waiting for window 'front-magritte' to be opened.
[0m[35mFastrak Device 'is900-default': Going into 'polled mode'
[0m[35mFastrak Device 'is900-default': [31mSending Intersense IS900 specific commands
[0m[0m[35mGot Output List Record for station 1: '21O40 2 4 1
22O40 2 42223 1
23O40 2 4 1
01    5 -97.51  21.21 -28.93 -34.81   3.75  -4.87
02   38 -87.88  43.72 -27.06  62.61 -10.23 -20.15   0  127 127
03   53 -84.89  51.66 -27.66 132.41  -5.93 -31.45
31PL00T20T30 00 00 00 00 00 00 00 00 00  132  
01    5 -97.51  21.21 -28.93 -34.66   3.66'
[0m[35mGot Output List Record for station 2: '22O40 2 42223 1
23O40 2 4 1
01    5 -97.51  21.21 -28.93 -34.81   3.75  -4.87
02   38 -87.88  43.72 -27.06  62.61 -10.23 -20.15   0  127 127
03   53 -84.89  51.66 -27.66 132.41  -5.93 -31.45
31PL00T20T30 00 00 00 00 00 00 00 00 00  132  
01    5 -97.51  21.21 -28.93 -34.66   3.66'
[0m[35mGot Output List Record for station 3: '23O40 2 4 1
01    5 -97.51  21.21 -28.93 -34.81   3.75  -4.87
02   38 -87.88  43.72 -27.06  62.61 -10.23 -20.15   0  127 127
03   53 -84.89  51.66 -27.66 132.41  -5.93 -31.45
31PL00T20T30 00 00 00 00 00 00 00 00 00  132  
01    5 -97.51  21.21 -28.93 -34.66   3.66'
[0m!!!! VR lib terminated

!!!! Graceful termination !!!!
