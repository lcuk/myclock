// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
#include <liqbase/vgraph.h>
#include <liqbase/liqaccel.h>		
		
//#####################################################################
//#####################################################################
//##################################################################### myclock_run :: by gary birkett
//#####################################################################
//#####################################################################





static int timer_tick(liqcell *self, liqcellmouseeventargs *args, liqcell *context)
{
	//liqapp_log("myclock tick tock '%s' %i", self->name,self->usagecount);
	liqcell_setdirty(context,1);
	// should also now adjust the timer so that we refresh without wasting anything :)
	// thanks jaffa :)
	unsigned long ticks = liqapp_GetTicks();
	#define REFRESH_STEP_MS 1000
	ticks = ticks % REFRESH_STEP_MS;
	liqcell_propseti(self,"timerinterval", (REFRESH_STEP_MS-ticks)+10 );
	//liqapp_log("ticks %i, togo %i",(int)ticks, (int)((1000-ticks)) );
	return 0;
}

		
/**	
 * myclock_run widget filter, the system is asking you to filter to the specified .
 */	
static int myclock_run_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
{
	// system is indicating the user has typed into the search box
	// you are expected to filter your content based upon this searchterm.
	// show or hide details and rearrange contents to apply this filter.
	char *searchterm = NULL;
	args->resultoutof=0;  // total number of searchable contents
	args->resultshown=0;  // count of options remaining after filtering.
	searchterm = args->searchterm;
	if(searchterm && *searchterm)
	{
		 // check the name property
		 args->resultoutof++;
		 if( stristr(self->name,searchterm) != NULL )
		 {
			  args->resultshown++;
		 }
		 // check the classname property
		 args->resultoutof++;
		 if( stristr(self->classname,searchterm) != NULL )
		 {
			  args->resultshown++;
		 }
		 // check any other properties or children and increment counters
		 // filter out list items recursively
	}
	return 0;
}
/**	
 * myclock_run widget refresh, all params set, present yourself to the user.
 */	
static int myclock_run_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_run dialog_open - the user zoomed into the dialog
 */	
static int myclock_run_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_run dialog_close - the dialog was closed
 */	
static int myclock_run_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_run widget shown - occurs once per lifetime
 */	
static int myclock_run_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_run mouse - occurs all the time as you stroke the screen
 */	
static int myclock_run_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_run click - occurs when a short mouse stroke occured
 */	
static int myclock_run_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_run keypress - the user pressed a key
 */	
static int myclock_run_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_run keyrelease - the user released a key
 */	
static int myclock_run_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_run paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
static int myclock_run_paint(liqcell *self, liqcellpainteventargs *args,liqcell *context)
{
//	// big heavy event, use sparingly
//	return 0;

	vgraph *graph = args->graph;

	liqcell *sketch_face = liqcell_child_lookup(self, "sketch_face");
	liqcell *sketch_hours = liqcell_child_lookup(self, "sketch_hours");
	liqcell *sketch_minutes = liqcell_child_lookup(self, "sketch_minutes");
	liqcell *sketch_seconds = liqcell_child_lookup(self, "sketch_seconds");
	
	liqsketch *sface = liqcell_getsketch(sketch_face);
	liqsketch *shour = liqcell_getsketch(sketch_hours);
	liqsketch *smins = liqcell_getsketch(sketch_minutes);
	liqsketch *ssecs = liqcell_getsketch(sketch_seconds);
	
	
	liqpointrange_start_xyz(&sface->boundingbox,0,0,0); liqpointrange_extendrubberband_xyz(&sface->boundingbox,400,400,400);
	liqpointrange_start_xyz(&shour->boundingbox,0,0,0); liqpointrange_extendrubberband_xyz(&shour->boundingbox,400,400,400);
	liqpointrange_start_xyz(&smins->boundingbox,0,0,0); liqpointrange_extendrubberband_xyz(&smins->boundingbox,400,400,400);
	liqpointrange_start_xyz(&ssecs->boundingbox,0,0,0); liqpointrange_extendrubberband_xyz(&ssecs->boundingbox,400,400,400);


    time_t     now;
    struct tm  *ts;
    time(&now);
    ts = localtime(&now);
	
	//ts->tm_min=ts->tm_sec;
	//ts->tm_hour=0;
	
	#define PI 3.141592654
	#define PI_2 (2*PI)
	
	ssecs->angle = ((float)(ts->tm_sec) * PI_2 / 60.0);
	smins->angle = ((float)(ts->tm_min) * PI_2 / 60.0);
	shour->angle = ((float)(ts->tm_hour % 12) * PI_2 / 12.0) + ((float)(ts->tm_min) * (PI_2/12.0) / 60.0) - (PI_2/4);


//	liqapp_log("TIME: Hr %2d %3.3f    Min %2d %3.3f    Sec %2d %3.3f", ts->tm_hour,shour->angle , ts->tm_min,smins->angle , ts->tm_sec,ssecs->angle);

/*
			int aax=0;
			int aay=0;
			int aaz=0;
			
			liqaccel_reset();			// eek, remove the laggy version :O should not be required and is a hack, should be able to ask for exact angle
			
			liqaccel_read(&aax,&aay,&aaz);
			
			//float faax = aax;
			//float faay = aay;
			//float oangle=atan2(faax,-faay );
		
			float a =  liqaccel_getangle();
			
			sface->angle = a;
			ssecs->angle += a;
			smins->angle += a;
			shour->angle += a;
	
*/
	
	
	
	vgraph_drawsketch(graph,   0,0, 480,480,  sface );
	vgraph_drawsketch(graph,   0,0, 480,480,  ssecs );
	vgraph_drawsketch(graph,   0,0, 480,480,  shour );
	vgraph_drawsketch(graph,   0,0, 480,480,  smins );


	
	return 0;

}
/**	
 * myclock_run dynamic resizing
 */	
static int myclock_run_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *canvass = liqcell_child_lookup(self, "canvass");
	liqcell_setrect_autoscale( canvass, 0,0, 480,480, sx,sy);
	return 0;
}

/**	
 * myclock_run_child_test_seek this function shows how to access members
 */	
	  
static void myclock_run_setcolours(liqcell *myclock_run)
{	  
//	liqcell *canvass = liqcell_child_lookup(myclock_run, "canvass");
	liqcell *sketch_face = liqcell_child_lookup(myclock_run, "sketch_face");
	liqcell *sketch_hours = liqcell_child_lookup(myclock_run, "sketch_hours");
	liqcell *sketch_minutes = liqcell_child_lookup(myclock_run, "sketch_minutes");
	liqcell *sketch_seconds = liqcell_child_lookup(myclock_run, "sketch_seconds");
	
	liqsketch *sface = liqcell_getsketch(sketch_face);
	liqsketch *shour = liqcell_getsketch(sketch_hours);
	liqsketch *smins = liqcell_getsketch(sketch_minutes);
	liqsketch *ssecs = liqcell_getsketch(sketch_seconds);
	
	// set the angle of each of these 3 based on the time as well as current orientation :)

						{
							liqstroke *s=sface->strokefirst;
							while(s)
							{
								s->pen_y=192;
								s->pen_u=128;
								s->pen_v=128;
								s=s->linknext;
							}
						}

						{
							liqstroke *s=shour->strokefirst;
							while(s)
							{
								s->pen_y=255;
								s->pen_u=10;
								s->pen_v=128;
								s=s->linknext;
							}
						}
						
						{
							liqstroke *s=smins->strokefirst;
							while(s)
							{
								s->pen_y=255;
								s->pen_u=128;
								s->pen_v=10;
								s=s->linknext;
							}
						}

						{
							liqstroke *s=ssecs->strokefirst;
							while(s)
							{
								s->pen_y=128;
								s->pen_u=128;
								s->pen_v=128;
								s=s->linknext;
							}
						}
	
}	  
/**	
 * create a new myclock_run widget
 */	
liqcell *myclock_run_create()
{
	liqcell *self = liqcell_quickcreatewidget("myclock_run", "form", 480, 480);
	if(!self) {liqapp_log("liqcell error not create 'myclock_run'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	
	liqcell *sketch_face = liqcell_quickcreatevis("sketch_face", "sketch", 0, 0, 480, 480);
	liqcell_setsketch(   sketch_face,    liqsketch_newfromfile("/usr/share/liqbase/myclock/media/liq.20110320_014720.lcuk.page.myclock.face"));
	liqcell_setvisible(sketch_face,0);
	liqcell_child_append(  self, sketch_face);

	liqcell *sketch_hours = liqcell_quickcreatevis("sketch_hours", "sketch", 0, 0, 480, 480);
	liqcell_setsketch(   sketch_hours,    liqsketch_newfromfile("/usr/share/liqbase/myclock/media/liq.20110320_014736.lcuk.page.myclock.hours"));
	liqcell_setvisible(sketch_hours,0);
	liqcell_child_append(  self, sketch_hours);

	liqcell *sketch_minutes = liqcell_quickcreatevis("sketch_minutes", "sketch", 0, 0, 480, 480);
	liqcell_setsketch(   sketch_minutes,    liqsketch_newfromfile("/usr/share/liqbase/myclock/media/liq.20110320_014745.lcuk.page.myclock.minutes"));
	liqcell_setvisible(sketch_minutes,0);
	liqcell_child_append(  self, sketch_minutes);

	liqcell *sketch_seconds = liqcell_quickcreatevis("sketch_seconds", "sketch", 0, 0, 480, 480);
	liqcell_setsketch(   sketch_seconds,    liqsketch_newfromfile("/usr/share/liqbase/myclock/media/liq.20110320_023951.lcuk.page.myclock.seconds"));
	liqcell_setvisible(sketch_seconds,0);
	liqcell_child_append(  self, sketch_seconds);


	myclock_run_setcolours(self);


	//############################# canvass:image
	liqcell *canvass = liqcell_quickcreatevis("canvass", "image", 0, 0, 480, 480);
	//liqcell_propsets(  canvass, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_run.canvass.png" );
	liqcell_child_append(  self, canvass);
	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/myclock/media/myclock_run_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)myclock_run_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)myclock_run_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)myclock_run_shown ,self);
	//liqcell_handleradd_withcontext(self, "resize",	  (void*)myclock_run_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)myclock_run_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)myclock_run_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)myclock_run_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)myclock_run_click ,self);
	liqcell_handleradd_withcontext(self, "paint",		(void*)myclock_run_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)myclock_run_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)myclock_run_dialog_close ,self);


		liqcell *timer1=liqcell_quickcreatevis("timer1",   "liqtimer",   0,0,   0,0 );
		liqcell_handleradd_withcontext(timer1,"timertick",timer_tick,self);
		liqcell_propseti(timer1,"timerinterval", 250 );
		liqcell_setenabled(timer1,1);
		liqcell_child_insert( self,timer1);
		
	return self;
}

