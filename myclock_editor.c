// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
		
		
//#####################################################################
//#####################################################################
//##################################################################### myclock_editor :: by gary birkett
//#####################################################################
//#####################################################################
		
		
/**	
 * myclock_editor widget filter, the system is asking you to filter to the specified .
 */	
static int myclock_editor_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
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
 * myclock_editor widget refresh, all params set, present yourself to the user.
 */	
static int myclock_editor_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor dialog_open - the user zoomed into the dialog
 */	
static int myclock_editor_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_editor dialog_close - the dialog was closed
 */	
static int myclock_editor_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_editor widget shown - occurs once per lifetime
 */	
static int myclock_editor_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor mouse - occurs all the time as you stroke the screen
 */	
static int myclock_editor_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor click - occurs when a short mouse stroke occured
 */	
static int myclock_editor_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor keypress - the user pressed a key
 */	
static int myclock_editor_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor keyrelease - the user released a key
 */	
static int myclock_editor_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_editor paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
//static int myclock_editor_paint(liqcell *self, liqcellpainteventargs *args,liqcell *context)
//{
//	// big heavy event, use sparingly
//	return 0;
//}
/**	
 * myclock_editor dynamic resizing
 */	
static int myclock_editor_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *cmdundo = liqcell_child_lookup(self, "cmdundo");
	liqcell *cmdclear = liqcell_child_lookup(self, "cmdclear");
	liqcell *cmdsave = liqcell_child_lookup(self, "cmdsave");
	liqcell *canvass = liqcell_child_lookup(self, "canvass");
	liqcell *titlebar1 = liqcell_child_lookup(self, "titlebar1");
	liqcell_setrect_autoscale( canvass, 208,62, 400,400, sx,sy);
	liqcell_setrect_autoscale( cmdundo, 0,432, 266,48, sx,sy);
	liqcell_setrect_autoscale( cmdclear, 266,432, 266,48, sx,sy);
	liqcell_setrect_autoscale( cmdsave, 532,432, 266,48, sx,sy);
	liqcell_setrect_autoscale( titlebar1, 0,0, 800,56, sx,sy);
	return 0;
}

/**	
 * myclock_editor.cmdundo clicked
 */	
static int cmdundo_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_editor)
{
	return 0;
}
/**	
 * myclock_editor.cmdclear clicked
 */	
static int cmdclear_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_editor)
{
	return 0;
}
/**	
 * myclock_editor.cmdsave clicked
 */	
static int cmdsave_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_editor)
{
	return 0;
}
/**	
 * myclock_editor_child_test_seek this function shows how to access members
 */	
	  
static void myclock_editor_child_test_seek(liqcell *myclock_editor)
{	  
	liqcell *cmdundo = liqcell_child_lookup(myclock_editor, "cmdundo");
	liqcell *cmdclear = liqcell_child_lookup(myclock_editor, "cmdclear");
	liqcell *cmdsave = liqcell_child_lookup(myclock_editor, "cmdsave");
	liqcell *canvass = liqcell_child_lookup(myclock_editor, "canvass");
	liqcell *titlebar1 = liqcell_child_lookup(myclock_editor, "titlebar1");
}	  
/**	
 * create a new myclock_editor widget
 */	
liqcell *myclock_editor_create()
{
	liqcell *self = liqcell_quickcreatewidget("myclock_editor", "form", 800, 480);
	if(!self) {liqapp_log("liqcell error not create 'myclock_editor'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	//############################# cmdundo:label
	liqcell *cmdundo = liqcell_quickcreatevis("cmdundo", "label", 0, 432, 266, 48);
	liqcell_setfont(	cmdundo, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdundo, "Undo" );
	liqcell_propsets(  cmdundo, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdundo, "backcolor", "xrgb(100,0,100)" );
	liqcell_propsets(  cmdundo, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdundo, "textalign", 2 );
	liqcell_propseti(  cmdundo, "textaligny", 2 );
	liqcell_setvisible(  cmdundo, 0 );
	liqcell_handleradd_withcontext(cmdundo, "click", (void*)cmdundo_click, self );
	liqcell_child_append(  self, cmdundo);
	//############################# cmdclear:label
	liqcell *cmdclear = liqcell_quickcreatevis("cmdclear", "label", 266, 432, 266, 48);
	liqcell_setfont(	cmdclear, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdclear, "Clear" );
	liqcell_propsets(  cmdclear, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdclear, "backcolor", "xrgb(0,0,100)" );
	liqcell_propsets(  cmdclear, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdclear, "textalign", 2 );
	liqcell_propseti(  cmdclear, "textaligny", 2 );
	liqcell_setvisible(  cmdclear, 0 );
	liqcell_handleradd_withcontext(cmdclear, "click", (void*)cmdclear_click, self );
	liqcell_child_append(  self, cmdclear);
	//############################# cmdsave:label
	liqcell *cmdsave = liqcell_quickcreatevis("cmdsave", "label", 532, 432, 266, 48);
	liqcell_setfont(	cmdsave, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdsave, "Save" );
	liqcell_propsets(  cmdsave, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdsave, "backcolor", "xrgb(0,100,0)" );
	liqcell_propsets(  cmdsave, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdsave, "textalign", 2 );
	liqcell_propseti(  cmdsave, "textaligny", 2 );
	liqcell_setvisible(  cmdsave, 0 );
	liqcell_handleradd_withcontext(cmdsave, "click", (void*)cmdsave_click, self );
	liqcell_child_append(  self, cmdsave);
	//############################# canvass:image
	liqcell *canvass = liqcell_quickcreatevis("canvass", "liqsketchedit", 208, 62, 400, 400);
	liqcell_propsets(  canvass, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_editor.canvass.png" );
	liqcell_propsets(  canvass, "bordercolor", "rgb(255,255,255)" );
	liqcell_child_append(  self, canvass);
	//############################# titlebar1:titlebar
	liqcell *titlebar1 = liqcell_quickcreatevis("titlebar1", "titlebar", 0, 0, 800, 56);
	liqcell_child_append(  self, titlebar1);
	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/myclock/media/myclock_editor_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)myclock_editor_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)myclock_editor_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)myclock_editor_shown ,self);
	//liqcell_handleradd_withcontext(self, "resize",	  (void*)myclock_editor_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)myclock_editor_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)myclock_editor_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)myclock_editor_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)myclock_editor_click ,self);
	//liqcell_handleradd_withcontext(self, "paint",		(void*)myclock_editor_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)myclock_editor_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)myclock_editor_dialog_close ,self);
	return self;
}

