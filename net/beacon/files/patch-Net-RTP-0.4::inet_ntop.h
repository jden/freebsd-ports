--- Net-RTP-0.4/inet_ntop.h.orig	Tue Mar  2 14:00:58 2004
+++ Net-RTP-0.4/inet_ntop.h	Tue Mar  2 14:02:27 2004
@@ -3,7 +3,11 @@
 extern "C" {
 #endif
 
+#ifdef __sparc64__ || __amd64__ || __alpha__
+const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
+#else
 const char *inet_ntop(int af, const void *src, char *dst, size_t size);
+#endif
 
 #if defined(__cplusplus)
 }
