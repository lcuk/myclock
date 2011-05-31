// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
		
		
//#####################################################################
//#####################################################################
//##################################################################### myclock_design :: by gary birkett
//#####################################################################
//#####################################################################
		
		
/**	
 * myclock_design widget filter, the system is asking you to filter to the specified .
 */	
static int myclock_design_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
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
 * myclock_design widget refresh, all params set, present yourself to the user.
 */	
static int myclock_design_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_design dialog_open - the user zoomed into the dialog
 */	
static int myclock_design_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_design dialog_close - the dialog was closed
 */	
static int myclock_design_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * myclock_design widget shown - occurs once per lifetime
 */	
static int myclock_design_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * myclock_design mouse - occurs all the time as you stroke the screen
 */	
static int myclock_design_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_design click - occurs when a short mouse stroke occured
 */	
static int myclock_design_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_design keypress - the user pressed a key
 */	
static int myclock_design_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_design keyrelease - the user released a key
 */	
static int myclock_design_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * myclock_design paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
//static int myclock_design_paint(liqcell *self, liqcellpainteventargs *args,liqcell *context)
//{
//	// big heavy event, use sparingly
//	return 0;
//}
/**	
 * myclock_design dynamic resizing
 */	
static int myclock_design_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *imaface = liqcell_child_lookup(self, "imaface");
	liqcell *imahours = liqcell_child_lookup(self, "imahours");
	liqcell *imaminutes = liqcell_child_lookup(self, "imaminutes");
	liqcell *cmdface = liqcell_child_lookup(self, "cmdface");
	liqcell *cmdhours = liqcell_child_lookup(self, "cmdhours");
	liqcell *cmdminutes = liqcell_child_lookup(self, "cmdminutes");
	liqcell *label4 = liqcell_child_lookup(self, "label4");
	liqcell *cmdsave = liqcell_child_lookup(self, "cmdsave");
	liqcell *label5 = liqcell_child_lookup(self, "label5");
	liqcell *titlebar1 = liqcell_child_lookup(self, "titlebar1");
	liqcell *txtname = liqcell_child_lookup(self, "txtname");
	liqcell_setrect_autoscale( imaface, 60,172, 196,196, sx,sy);
	liqcell_setrect_autoscale( imahours, 298,172, 196,196, sx,sy);
	liqcell_setrect_autoscale( imaminutes, 534,172, 196,196, sx,sy);
	liqcell_setrect_autoscale( cmdface, 72,368, 174,32, sx,sy);
	liqcell_setrect_autoscale( cmdhours, 308,368, 174,32, sx,sy);
	liqcell_setrect_autoscale( cmdminutes, 544,368, 174,32, sx,sy);
	liqcell_setrect_autoscale( label4, 66,52, 664,34, sx,sy);
	liqcell_setrect_autoscale( cmdsave, 540,424, 260,56, sx,sy);
	liqcell_setrect_autoscale( label5, 64,104, 174,32, sx,sy);
	liqcell_setrect_autoscale( titlebar1, 0,0, 800,56, sx,sy);
	liqcell_setrect_autoscale( txtname, 296,88, 434,70, sx,sy);
	return 0;
}

/**	
 * myclock_design.imaface clicked
 */	
static int imaface_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *imafacedialog = liqcell_quickcreatevis("myclock_design_imaface_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( imafacedialog );
	liqcell_release( imafacedialog );
	return 0;
}
/**	
 * myclock_design.imahours clicked
 */	
static int imahours_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *imahoursdialog = liqcell_quickcreatevis("myclock_design_imahours_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( imahoursdialog );
	liqcell_release( imahoursdialog );
	return 0;
}
/**	
 * myclock_design.imaminutes clicked
 */	
static int imaminutes_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *imaminutesdialog = liqcell_quickcreatevis("myclock_design_imaminutes_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( imaminutesdialog );
	liqcell_release( imaminutesdialog );
	return 0;
}
/**	
 * myclock_design.cmdface clicked
 */	
static int cmdface_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *cmdfacedialog = liqcell_quickcreatevis("myclock_design_cmdface_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( cmdfacedialog );
	liqcell_release( cmdfacedialog );
	return 0;
}
/**	
 * myclock_design.cmdhours clicked
 */	
static int cmdhours_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *cmdhoursdialog = liqcell_quickcreatevis("myclock_design_cmdhours_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( cmdhoursdialog );
	liqcell_release( cmdhoursdialog );
	return 0;
}
/**	
 * myclock_design.cmdminutes clicked
 */	
static int cmdminutes_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	//# run the associated dialog
	liqcell *cmdminutesdialog = liqcell_quickcreatevis("myclock_design_cmdminutes_dialog", "myclock_editor", 0,0, -1,-1);
	liqcell_easyrun( cmdminutesdialog );
	liqcell_release( cmdminutesdialog );
	return 0;
}
/**	
 * myclock_design.cmdsave clicked
 */	
static int cmdsave_click(liqcell *self,liqcellclickeventargs *args, liqcell *myclock_design)
{
	return 0;
}
/**	
 * myclock_design_child_test_seek this function shows how to access members
 */	
	  
static void myclock_design_child_test_seek(liqcell *myclock_design)
{	  
	liqcell *imaface = liqcell_child_lookup(myclock_design, "imaface");
	liqcell *imahours = liqcell_child_lookup(myclock_design, "imahours");
	liqcell *imaminutes = liqcell_child_lookup(myclock_design, "imaminutes");
	liqcell *cmdface = liqcell_child_lookup(myclock_design, "cmdface");
	liqcell *cmdhours = liqcell_child_lookup(myclock_design, "cmdhours");
	liqcell *cmdminutes = liqcell_child_lookup(myclock_design, "cmdminutes");
	liqcell *label4 = liqcell_child_lookup(myclock_design, "label4");
	liqcell *cmdsave = liqcell_child_lookup(myclock_design, "cmdsave");
	liqcell *label5 = liqcell_child_lookup(myclock_design, "label5");
	liqcell *titlebar1 = liqcell_child_lookup(myclock_design, "titlebar1");
	liqcell *txtname = liqcell_child_lookup(myclock_design, "txtname");
}	  
/**	
 * create a new myclock_design widget
 */	
liqcell *myclock_design_create()
{
	liqcell *self = liqcell_quickcreatewidget("myclock_design", "form", 800, 480);
	if(!self) {liqapp_log("liqcell error not create 'myclock_design'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	//############################# imaface:image
	liqcell *imaface = liqcell_quickcreatevis("imaface", "image", 60, 172, 196, 196);
	liqcell_propsets(  imaface, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_design.imaface.png" );
	liqcell_propsets(  imaface, "bordercolor", "rgb(255,255,255)" );
	liqcell_handleradd_withcontext(imaface, "click", (void*)imaface_click, self );
	liqcell_child_append(  self, imaface);
	//############################# imahours:image
	liqcell *imahours = liqcell_quickcreatevis("imahours", "image", 298, 172, 196, 196);
	liqcell_propsets(  imahours, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_design.imahours.png" );
	liqcell_propsets(  imahours, "bordercolor", "rgb(255,255,255)" );
	liqcell_handleradd_withcontext(imahours, "click", (void*)imahours_click, self );
	liqcell_child_append(  self, imahours);
	//############################# imaminutes:image
	liqcell *imaminutes = liqcell_quickcreatevis("imaminutes", "image", 534, 172, 196, 196);
	liqcell_propsets(  imaminutes, "imagefilename", "/usr/share/liqbase/myclock/media/myclock_design.imaminutes.png" );
	liqcell_propsets(  imaminutes, "bordercolor", "rgb(255,255,255)" );
	liqcell_handleradd_withcontext(imaminutes, "click", (void*)imaminutes_click, self );
	liqcell_child_append(  self, imaminutes);
	//############################# cmdface:label
	liqcell *cmdface = liqcell_quickcreatevis("cmdface", "label", 72, 368, 174, 32);
	liqcell_setfont(	cmdface, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(cmdface, "Clock Face" );
	liqcell_propsets(  cmdface, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdface, "backcolor", "xrgb(0,0,0)" );
	liqcell_propsets(  cmdface, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdface, "textalign", 2 );
	liqcell_propseti(  cmdface, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdface, "click", (void*)cmdface_click, self );
	liqcell_child_append(  self, cmdface);
	//############################# cmdhours:label
	liqcell *cmdhours = liqcell_quickcreatevis("cmdhours", "label", 308, 368, 174, 32);
	liqcell_setfont(	cmdhours, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(cmdhours, "Hours Hand" );
	liqcell_propsets(  cmdhours, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdhours, "backcolor", "xrgb(0,0,0)" );
	liqcell_propsets(  cmdhours, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdhours, "textalign", 2 );
	liqcell_propseti(  cmdhours, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdhours, "click", (void*)cmdhours_click, self );
	liqcell_child_append(  self, cmdhours);
	//############################# cmdminutes:label
	liqcell *cmdminutes = liqcell_quickcreatevis("cmdminutes", "label", 544, 368, 174, 32);
	liqcell_setfont(	cmdminutes, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(cmdminutes, "Minutes Hand" );
	liqcell_propsets(  cmdminutes, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdminutes, "backcolor", "xrgb(0,0,0)" );
	liqcell_propsets(  cmdminutes, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdminutes, "textalign", 2 );
	liqcell_propseti(  cmdminutes, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdminutes, "click", (void*)cmdminutes_click, self );
	liqcell_child_append(  self, cmdminutes);
	//############################# label4:label
	liqcell *label4 = liqcell_quickcreatevis("label4", "label", 66, 52, 664, 34);
	liqcell_setfont(	label4, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(label4, "Create the components for your customised clock" );
	liqcell_propsets(  label4, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  label4, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  label4, "textalign", 0 );
	liqcell_propseti(  label4, "textaligny", 0 );
	liqcell_child_append(  self, label4);
	//############################# cmdsave:label
	liqcell *cmdsave = liqcell_quickcreatevis("cmdsave", "label", 540, 424, 260, 56);
	liqcell_setfont(	cmdsave, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdsave, "Save" );
	liqcell_propsets(  cmdsave, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  cmdsave, "backcolor", "xrgb(0,64,0)" );
	liqcell_propsets(  cmdsave, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  cmdsave, "textalign", 2 );
	liqcell_propseti(  cmdsave, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdsave, "click", (void*)cmdsave_click, self );
	liqcell_child_append(  self, cmdsave);
	//############################# label5:label
	liqcell *label5 = liqcell_quickcreatevis("label5", "label", 64, 104, 174, 32);
	liqcell_setfont(	label5, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (22), 0) );
	liqcell_setcaption(label5, "Name:" );
	liqcell_propsets(  label5, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  label5, "backcolor", "rgb(0,0,0)" );
	liqcell_propseti(  label5, "textalign", 2 );
	liqcell_propseti(  label5, "textaligny", 2 );
	liqcell_child_append(  self, label5);
	//############################# titlebar1:titlebar
	liqcell *titlebar1 = liqcell_quickcreatevis("titlebar1", "titlebar", 0, 0, 800, 56);
	liqcell_child_append(  self, titlebar1);
	//############################# txtname:textbox
	liqcell *txtname = liqcell_quickcreatevis("txtname", "textbox", 296, 88, 434, 70);
	liqcell_setfont(	txtname, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (43), 0) );
	liqcell_setcaption(txtname, "Clock Name" );
	liqcell_propsets(  txtname, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  txtname, "backcolor", "rgb(0,0,0)" );
	liqcell_propsets(  txtname, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  txtname, "textalign", 0 );
	liqcell_propseti(  txtname, "textaligny", 0 );
	liqcell_child_append(  self, txtname);
	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/myclock/media/myclock_design_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)myclock_design_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)myclock_design_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)myclock_design_shown ,self);
	//liqcell_handleradd_withcontext(self, "resize",	  (void*)myclock_design_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)myclock_design_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)myclock_design_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)myclock_design_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)myclock_design_click ,self);
	//liqcell_handleradd_withcontext(self, "paint",		(void*)myclock_design_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)myclock_design_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)myclock_design_dialog_close ,self);
	return self;
}

