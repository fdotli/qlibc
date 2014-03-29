 * qLibc
 * Copyright (c) 2010-2014 Seungyoung Kim.
 *****************************************************************************/
#include <errno.h>
#include "utilities/qstring.h"
#include "extensions/qlog.h"
 * @param options         combination of options.
 * @note
 *   Available options:
 *   - QLOG_OPT_THREADSAFE - make it thread-safe.
 *   - QLOG_OPT_FLUSH -  flush out buffer everytime.
 *
 *   qlog_t *log = qlog("/tmp/qdecoder-%Y%m%d.err", 0644, 86400, QLOG_OPT_THREADSAFE);
             int options) {
    // malloc qlog_t structure
    log = (qlog_t *) calloc(1, sizeof(qlog_t));
    if (log == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    // set up the structure.
    if (rotateinterval > 0)
        log->rotateinterval = rotateinterval;

    // handle options
    if (options & QLOG_OPT_THREADSAFE) {
        Q_MUTEX_NEW(log->qmutex, true);
        if (log->qmutex == NULL) {
            errno = ENOMEM;
            free(log);
            return NULL;
        }
    }
    if (options & QLOG_OPT_FLUSH) {
        log->logflush = true;
    }
    // try to open the log file.
        Q_MUTEX_DESTROY(log->qmutex);
    log->write = write_;
    log->duplicate = duplicate;
    log->flush = flush_;
    log->free = free_;
static bool write_(qlog_t *log, const char *str) {
    if (log == NULL || log->fp == NULL)
        return false;
        if (log->outflush == true)
            fflush(log->outfp);
    /* check if log rotation is needed */
        if (log->logflush == true)
            fflush(log->fp);
static bool writef(qlog_t *log, const char *format, ...) {
    if (log == NULL || log->fp == NULL)
        return false;
    if (str == NULL)
        return false;
static bool duplicate(qlog_t *log, FILE *outfp, bool flush) {
    if (log == NULL)
        return false;
static bool flush_(qlog_t *log) {
    if (log == NULL)
        return false;
    if (log->fp != NULL && log->logflush == false)
        fflush(log->fp);
    if (log->outfp != NULL && log->outflush == false)
        fflush(log->outfp);
static void free_(qlog_t *log) {
    if (log == NULL)
        return;
static bool _real_open(qlog_t *log) {
        if (log->mode != 0)
            fchmod(fileno(log->fp), log->mode);
         existing one */
            if (log->mode != 0)
                fchmod(fileno(newfp), log->mode);
                    newfilepath);
                * log->rotateinterval - dt;