//
// "$Id: Fl_Progress.cxx,v 1.1.2.1 2001/08/11 14:49:51 easysw Exp $"
//
// Progress bar widget routines.
//
// Copyright 2000-2001 by Michael Sweet.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@fltk.org".
//
// Contents:
//
//   Fl_Progress::draw()        - Draw the check button.
//   Fl_Progress::Fl_Progress() - Construct a Fl_Progress widget.
//

//
// Include necessary header files...
//

#include <FL/Fl.H>
#include "Fl_Progress.H"
#include <FL/fl_draw.H>
#include <stdio.h>

//
// Fl_Progress is a progress bar widget based off Fl_Widget that shows a
// standard progress bar...
//


//
// 'Fl_Progress::draw()' - Draw the check button.
//

void Fl_Progress::draw()
{
  int	progress;	// Size of progress bar...
  int	bx, by, bw, bh;	// Box areas...


  // Get the box borders...
  bx = Fl::box_dx(box());
  by = Fl::box_dy(box());
  bw = Fl::box_dw(box());
  bh = Fl::box_dh(box());

  // Draw the box...
  draw_box(box(), x(), y(), w(), h(), color());

  // Draw the progress bar...
  if (maximum_ > minimum_)
    progress = (int)((w() - bw) * (value_ - minimum_) /
                                  (maximum_ - minimum_) + 0.5f);
  else
    progress = 0;

  if (progress > 0)
  {
    fl_clip(x() + bx, y() + by, w() - bw, h() - bh);

    //The Next line is for FLTK 1.0.x 
    //    fl_color(active_r() ? color2() : inactive(color2()));
    //If you are using FLTK 1.1.x please comment out the above line and uncomment the next
    
     fl_color(active_r() ? color2() : fl_inactive(color2()));        
    //
    //
    fl_polygon(x() + bx, y() + by,
               x() + bx, y() + h() - by,
	       x() + 5 + progress - h() / 4, y() + h() - by,
               x() + 2 + progress + h() / 4, y() + by);

    fl_pop_clip();
  }

char buffer[30];
                sprintf(buffer, "%d%%", (int) (((value_ - minimum_)/(maximum_-minimum_))* 100));
                fl_color(FL_BLUE);
                fl_font(this->labelfont(), this->labelsize());
                fl_draw(buffer, x() + (w() - fl_width(buffer))/2, y() + fl_height() + (((h() - 2*by) - fl_height())/2));


  // Finally, the label...
  draw_label(x() + bx, y() + by, w() - bw, h() - bh);
}


//
// 'Fl_Progress::Fl_Progress()' - Construct a Fl_Progress widget.
//

Fl_Progress::Fl_Progress(int x, int y, int w, int h, const char* l)
: Fl_Widget(x, y, w, h, l)
{
  align(FL_ALIGN_INSIDE);
  box(FL_DOWN_BOX);
  color(FL_WHITE, FL_GREEN);
  minimum(0.0f);
  maximum(100.0f);
  value(0.0f);
}


//
// End of "$Id: Fl_Progress.cxx,v 1.1.2.1 2001/08/11 14:49:51 easysw Exp $".
//
