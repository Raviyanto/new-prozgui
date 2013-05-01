/* netrc.h -- declarations for netrc.c
   Copyright (C) 1996, Free Software Foundation, Inc.
   Gordon Matzigkeit <gord@gnu.ai.mit.edu>, 1996

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* $Id: netrc.h,v 1.11 2001/05/30 15:01:40 kalum Exp $ */
/* $Id: netrc.h,v 1.12 2011/03/29 15:01:40 ahmad Exp $ */

#ifndef NETRC_H
#define NETRC_H


#include "common.h"


#undef __BEGIN_DECLS
#undef __END_DECLS

#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS		/* Empty. */
# define __END_DECLS		/* Empty. */
#endif

#undef __P
#if defined (__STDC__) || defined (_AIX) || (defined (__mips) && defined (_SYSTYPE_SVR4)) || defined(WIN32) || defined(__cplusplus)
# define __P(protos) protos
#else
# define __P(protos) ()
#endif

/* The structure used to return account information from the .netrc. */
typedef struct _netrc_entry {
  /* The exact host name given in the .netrc, NULL if default. */
  char *host;

  /* The name of the account. */
  char *account;

  /* Password for the account (NULL, if none). */
  char *password;

  /* Pointer to the next entry in the list. */
  struct _netrc_entry *next;
} netrc_entry;

__BEGIN_DECLS netrc_entry *parse_netrc __P((char *file));
netrc_entry *search_netrc __P((netrc_entry * list, const char *host));

__END_DECLS
#endif				/* NETRC_H */
