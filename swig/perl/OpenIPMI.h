/*
 * OpenIPMI.h
 *
 * Include file for SWIG/Perl interface
 *
 * Author: MontaVista Software, Inc.
 *         Corey Minyard <minyard@mvista.com>
 *         source@mvista.com
 *
 * Copyright 2004 MontaVista Software Inc.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *
 *  THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __SWIG_PERL_OPENIPMIH
#define __SWIG_PERL_OPENIPMIH

/* A callback object.  Note that this is the one that will be passed
   in by the user.  For Perl, we want the real reference, which is a
   swig_cb_val. */
typedef SV *swig_cb;

/* The real underlying reference to the callback object.  This should
   always be a pointer. */
typedef SV *swig_cb_val;

/* Get the underlying callback object reference. */
swig_cb_val get_swig_cb(swig_cb cb);

/* Get the underlying callback object reference and increment its refcount. */
swig_cb_val ref_swig_cb(swig_cb cb);

/* Get the underlying callback object reference and decrement its refcount. */
swig_cb_val deref_swig_cb(swig_cb cb);

/* Decrement the underlying callback object refcount. */
swig_cb_val deref_swig_cb_val(swig_cb_val cb);

/* Used to validate the CB values passed in by the user. */
#define valid_swig_cb(v) ((v) && (SvOK(v)) && (SvOK(SvRV(v))))
#define invalidate_swig_cb(v) ((v) = NULL)


void swig_call_cb(swig_cb_val cb, char *method_name, char *format, ...)
#ifdef __GNUC__
     __attribute__ ((__format__ (__printf__, 3, 4)))
#endif
;


typedef struct swig_ref
{
    SV *val;
} swig_ref;


swig_ref swig_make_ref(void *item, char *name);
void swig_free_ref(swig_ref ref);

/* Make a reference whose destructor will be called when everything
   is done with it. */
swig_ref swig_make_ref_destruct(void *item, char *class);


#define swig_free_ref_check(r, c) \
	do {								\
	    if (SvREFCNT(SvRV(r.val)) != 1)				\
		warn("***You cannot keep pointers of class %s", c);	\
	    swig_free_ref(r);						\
	} while(0)

#endif /* __SWIG_PERL_OPENIPMIH */