// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
		
		
//#####################################################################
//#####################################################################
//##################################################################### myclock_cover :: by gary birkett
//#####################################################################
//#####################################################################
		
		
/**	
 * myclock_cover widget filter, the system is asking you to filter to the specified .
 */	
static int myclock_cover_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
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
 * myclock_cover widget refresh, all params set, present yourself to the user.
 */	
static int myclock_cover_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover dialog_open - the user zoomed into the dialog
 */	
static int myclock_cover_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_cover dialog_close - the dialog was closed
 */	
static int myclock_cover_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_cover widget shown - occurs once per lifetime
 */	
static int myclock_cover_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover mouse - occurs all the time as you stroke the screen
 */	
static int myclock_cover_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover click - occurs when a short mouse stroke occured
 */	
static int myclock_cover_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover keypress - the user pressed a key
 */	
static int myclock_cover_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover keyrelease - the user released a key
 */	
static int myclock_cover_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_cover paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
//static int myclock_cover_paint(liqcell *self, liqcellpainteventargs *args,liqcell *context)
//{
//	// big heavy event, use sparingly
//	return 0;
//}
/**	
 * myclock_cover dynamic resizing
 */	
static int myclock_cover_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *label3 = liqcell_child_lookup(self, "label3");
	liqcell *lbltitle = liqcell_child_lookup(self, "lbltitle");
	liqcell *author = liqcell_child_lookup(self, "author");
	liqcell *slidetext3 = liqcell_child_lookup(self, "slidetext3");
	liqcell *slidetext2 = liqcell_child_lookup(self, "slidetext2");
	liqcell *slidetext1 = liqcell_child_lookup(self, "slidetext1");
	liqcell *cmdclockfacecreate = liqcell_child_lookup(self, "cmdclockfacecreate");
	liqcell *cmdclockfacemanage = liqcell_child_lookup(self, "cmdclockfacemanage");
	liqcell *preview = liqcell_child_lookup(self, "preview");
	liqcell_setrect_autoscale( preview, 456,148, 264,256, sx,sy);
	liqcell_setrect_autoscale( label3, 14,446, 764,30, sx,sy);
	liqcell_setrect_autoscale( lbltitle, 0,0, 800,80, sx,sy);
	liqcell_setrect_autoscale( author, 24,84, 696,48, sx,sy);
	liqcell_setrect_autoscale( slidetext3, 26,224, 442,30, sx,sy);
	liqcell_setrect_autoscale( slidetext2, 26,182, 442,30, sx,sy);
	liqcell_setrect_autoscale( slidetext1, 26,142, 442,30, sx,sy);
	liqcell_setrect_autoscale( cmdclockfacecreate, 32,264, 340,80, sx,sy);
	liqcell_setrect_autoscale( cmdclockfacemanage, 32,354, 340,80, sx,sy);
	return 0;
}

/**	
 * myclock_cover.cmdclockfacecreate clicked
 */	
static int cmdclockfacecreate_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_cover)
{
	//# run the associated dialog
	liqcell *cmdclockfacecreatedialog = liqcell_quickcreatevis("myclock_cover_cmdclockfacecreate_dialog", "myclock_design", 0,0, -1,-1);
	liqcell_easyrun( cmdclockfacecreatedialog );
	liqcell_release( cmdclockfacecreatedialog );
	return 0;
}
/**	
 * myclock_cover.cmdclockfacemanage clicked
 */	
static int cmdclockfacemanage_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_cover)
{
	return 0;
}
/**	
 * myclock_cover_child_test_seek this function shows how to access members
 */	
	  
static void myclock_cover_child_test_seek(liqcell *myclock_cover)
{	  
	liqcell *label3 = liqcell_child_lookup(myclock_cover, "label3");
	liqcell *lbltitle = liqcell_child_lookup(myclock_cover, "lbltitle");
	liqcell *author = liqcell_child_lookup(myclock_cover, "author");
	liqcell *slidetext3 = liqcell_child_lookup(myclock_cover, "slidetext3");
	liqcell *slidetext2 = liqcell_child_lookup(myclock_cover, "slidetext2");
	liqcell *slidetext1 = liqcell_child_lookup(myclock_cover, "slidetext1");
	liqcell *cmdclockfacecreate = liqcell_child_lookup(myclock_cover, "cmdclockfacecreate");
	liqcell *cmdclockfacemanage = liqcell_child_lookup(myclock_cover, "cmdclockfacemanage");
	liqcell *preview = liqcell_child_lookup(myclock_cover, "preview");
}

/**	
 * myclock.dirty clicked
 */	
static int myclock_dirty(liqcell *self,liqcelleventargs *args, liqcell *myclock_cover)
{
	liqcell_setdirty(myclock_cover,1);
	return 0;
}


/**	
 * create a new myclock_cover widget
 */	
liqcell *myclock_cover_create()
{
	liqcell *self = liqcell_quickcreatewidget("myclock_cover", "form", 800, 480);
	if(!self) {liqapp_log("liqcell error not create 'myclock_cover'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	//############################# label3:label
	liqcell *label3 = liqcell_quickcreatevis("label3", "label", 14, 446, 764, 30);
	liqcell_setfont(	label3, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (19), 0) );
	liqcell_setcaption(label3, "open source comes from the heart.  please donate to all projects." );
	liqcell_propsets(  label3, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  label3, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  label3, "textalign", 2 );
	liqcell_propseti(  label3, "textaligny", 2 );
	liqcell_setvisible(label3,0);
	liqcell_child_append(  self, label3);
	//############################# lbltitle:label
	liqcell *lbltitle = liqcell_quickcreatevis("lbltitle", "label", 0, 0, 800, 80);
	liqcell_setfont(	lbltitle, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (58), 0) );
	liqcell_setcaption(lbltitle, "My Clock" );
	liqcell_propsets(  lbltitle, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  lbltitle, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  lbltitle, "textalign", 0 );
	liqcell_propseti(  lbltitle, "textaligny", 0 );
	liqcell_child_append(  self, lbltitle);
	//############################# author:label
	liqcell *author = liqcell_quickcreatevis("author", "label", 24, 84, 696, 48);
	liqcell_setfont(	author, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(author, "written by Gary Birkett." );
	liqcell_propsets(  author, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  author, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  author, "textalign", 0 );
	liqcell_propseti(  author, "textaligny", 0 );
	liqcell_child_append(  self, author);
	//############################# slidetext3:label
	liqcell *slidetext3 = liqcell_quickcreatevis("slidetext3", "label", 26, 224, 442, 30);
	liqcell_setfont(	slidetext3, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (19), 0) );
	liqcell_setcaption(slidetext3, "Distinctive analogue design." );
	liqcell_propsets(  slidetext3, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  slidetext3, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  slidetext3, "textalign", 0 );
	liqcell_propseti(  slidetext3, "textaligny", 0 );
	liqcell_child_append(  self, slidetext3);
	//############################# slidetext2:label
	liqcell *slidetext2 = liqcell_quickcreatevis("slidetext2", "label", 26, 182, 442, 30);
	liqcell_setfont(	slidetext2, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (19), 0) );
	liqcell_setcaption(slidetext2, "Unique hand written digital" );
	liqcell_propsets(  slidetext2, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  slidetext2, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  slidetext2, "textalign", 0 );
	liqcell_propseti(  slidetext2, "textaligny", 0 );
	liqcell_child_append(  self, slidetext2);
	//############################# slidetext1:label
	liqcell *slidetext1 = liqcell_quickcreatevis("slidetext1", "label", 26, 142, 442, 30);
	liqcell_setfont(	slidetext1, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (19), 0) );
	liqcell_setcaption(slidetext1, "A personal clock." );
	liqcell_propsets(  slidetext1, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  slidetext1, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  slidetext1, "textalign", 0 );
	liqcell_propseti(  slidetext1, "textaligny", 0 );
	liqcell_child_append(  self, slidetext1);
	//############################# cmdclockfacecreate:label
	liqcell *cmdclockfacecreate = liqcell_quickcreatevis("cmdclockfacecreate", "label", 32, 264, 340, 80);
	liqcell_setfont(	cmdclockfacecreate, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdclockfacecreate, "Create Clock Face" );
	liqcell_propsets(  cmdclockfacecreate, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdclockfacecreate, "backcolor", "xrgb(0,64,0)" );
	liqcell_propsets(  cmdclockfacecreate, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdclockfacecreate, "textalign", 2 );
	liqcell_propseti(  cmdclockfacecreate, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdclockfacecreate, "click", (void*)cmdclockfacecreate_click, self );
	liqcell_child_append(  self, cmdclockfacecreate);
	//############################# cmdclockfacemanage:label
	liqcell *cmdclockfacemanage = liqcell_quickcreatevis("cmdclockfacemanage", "label", 32, 354, 340, 80);
	liqcell_setfont(	cmdclockfacemanage, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdclockfacemanage, "View History" );
	liqcell_propsets(  cmdclockfacemanage, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdclockfacemanage, "backcolor", "xrgb(0,64,0)" );
	liqcell_propsets(  cmdclockfacemanage, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdclockfacemanage, "textalign", 2 );
	liqcell_propseti(  cmdclockfacemanage, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdclockfacemanage, "click", (void*)cmdclockfacemanage_click, self );
	liqcell_child_append(  self, cmdclockfacemanage);
	//############################# preview:image
	liqcell *preview = liqcell_quickcreatevis("preview", "image", 456, 148, 264, 256);
	liqcell_propseti(preview,"lockaspect",1);
		liqcell *myclock1 = liqcell_quickcreatevis("myclock1", "myclock.myclock_run", 0,0, 0,0);
		liqcell_handleradd_withcontext(myclock1,    "dirty",   myclock_dirty, self );
	liqcell_setcontent(preview, myclock1 );
	

	//liqcell_propsets(  preview, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_cover.preview.png" );
	liqcell_child_append(  self, preview);
	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/myclock/media/myclock_cover_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)myclock_cover_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)myclock_cover_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)myclock_cover_shown ,self);
	//liqcell_handleradd_withcontext(self, "resize",	  (void*)myclock_cover_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)myclock_cover_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)myclock_cover_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)myclock_cover_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)myclock_cover_click ,self);
	//liqcell_handleradd_withcontext(self, "paint",		(void*)myclock_cover_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)myclock_cover_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)myclock_cover_dialog_close ,self);
	return self;
}

