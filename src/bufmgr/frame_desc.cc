#include "bufmgr/frame_desc.h"

frame_desc::frame_desc() : page_id_(INVALID_PAGEID), prev_frame_no_(-1), next_frame_no_(-1)
{}

frame_desc::~frame_desc()
{
    page_id_ = INVALID_PAGEID;
    prev_frame_no_ = -1;
    next_frame_no_ = -1;
}

