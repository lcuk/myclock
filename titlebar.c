// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
		
		
//#####################################################################
//#####################################################################
//##################################################################### titlebar :: by gary birkett
//#####################################################################
//#####################################################################
		
		
/**	
 * titlebar widget filter, the system is asking you to filter to the specified .
 */	
static int titlebar_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
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
 * titlebar widget refresh, all params set, present yourself to the user.
 */	
static int titlebar_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * titlebar dialog_open - the user zoomed into the dialog
 */	
static int titlebar_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * titlebar dialog_close - the dialog was closed
 */	
static int titlebar_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * titlebar widget shown - occurs once per lifetime
 */	
static int titlebar_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * titlebar mouse - occurs all the time as you stroke the screen
 */	
static int titlebar_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * titlebar click - occurs when a short mouse stroke occured
 */	
static int titlebar_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * titlebar keypress - the user pressed a key
 */	
static int titlebar_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * titlebar keyrelease - the user released a key
 */	
static int titlebar_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * titlebar paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
//static int titlebar_paint(liqcell *self, liqcellpainteventargs *args,liqcell *context)
//{
//	// big heavy event, use sparingly
//	return 0;
//}
/**	
 * titlebar dynamic resizing
 */	
static int titlebar_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *image1 = liqcell_child_lookup(self, "image1");
	liqcell *lbltitle = liqcell_child_lookup(self, "lbltitle");
	liqcell *iconifiy = liqcell_child_lookup(self, "iconifiy");
	liqcell *imaback = liqcell_child_lookup(self, "imaback");
	liqcell_setrect_autoscale( image1, 2,4, 60,46, sx,sy);
	liqcell_setrect_autoscale( lbltitle, 66,12, 448,28, sx,sy);
	liqcell_setrect_autoscale( iconifiy, 6,6, 46,42, sx,sy);
	liqcell_setrect_autoscale( imaback, 450,0, 82,54, sx,sy);
	return 0;
}

/**	
 * titlebar_child_test_seek this function shows how to access members
 */	
	  
static void titlebar_child_test_seek(liqcell *titlebar)
{	  
	liqcell *image1 = liqcell_child_lookup(titlebar, "image1");
	liqcell *lbltitle = liqcell_child_lookup(titlebar, "lbltitle");
	liqcell *iconifiy = liqcell_child_lookup(titlebar, "iconifiy");
	liqcell *imaback = liqcell_child_lookup(titlebar, "imaback");
}	  
/**	
 * create a new titlebar widget
 */	
liqcell *titlebar_create()
{
	liqcell *self = liqcell_quickcreatewidget("titlebar", "form", 544, 56);
	if(!self) {liqapp_log("liqcell error not create 'titlebar'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	//############################# image1:image
	liqcell *image1 = liqcell_quickcreatevis("image1", "image", 2, 4, 60, 46);
	liqcell_propsets(  image1, "imagefilename", "/usr/share/liqbase/myclock/media/titlebar.image1.png" );
	liqcell_child_append(  self, image1);
	//############################# lbltitle:label
	liqcell *lbltitle = liqcell_quickcreatevis("lbltitle", "label", 66, 12, 448, 28);
	liqcell_setfont(	lbltitle, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(lbltitle, "Caption Goes Here" );
	liqcell_propsets(  lbltitle, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  lbltitle, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  lbltitle, "textalign", 0 );
	liqcell_propseti(  lbltitle, "textaligny", 0 );
	liqcell_child_append(  self, lbltitle);
	//############################# iconifiy:image
	liqcell *iconifiy = liqcell_quickcreatevis("iconifiy", "image", 6, 6, 46, 42);
	liqcell_propsets(  iconifiy, "imagefilename", "/usr/share/liqbase/myclock/media/titlebar.iconifiy.png" );
	liqcell_propsets(  iconifiy, "bordercolor", "rgb(255,255,255)" );
	liqcell_child_append(  self, iconifiy);
	//############################# imaback:image
	liqcell *imaback = liqcell_quickcreatevis("imaback", "image", 450, 0, 82, 54);
	liqcell_propsets(  imaback, "imagefilename", "/usr/share/liqbase/myclock/media/titlebar.imaback.png" );
	liqcell_child_append(  self, imaback);
	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/myclock/media/titlebar_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)titlebar_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)titlebar_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)titlebar_shown ,self);
	//liqcell_handleradd_withcontext(self, "resize",	  (void*)titlebar_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)titlebar_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)titlebar_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)titlebar_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)titlebar_click ,self);
	//liqcell_handleradd_withcontext(self, "paint",		(void*)titlebar_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)titlebar_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)titlebar_dialog_close ,self);
	return self;
}

