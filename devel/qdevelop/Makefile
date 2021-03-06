# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	qdevelop
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	http://biord-software.org/downloads/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Development environment entirely dedicated to Qt 4

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_QT4=	gui sql network xml designer sql-sqlite3_run \
		moc_build uic_build rcc_build
USES=		qmake

STRIP_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES=	"QDevelop" \
			"Qt 4 development environment" \
			"${PREFIX}/share/pixmaps/qdevelop.png" \
			"qdevelop" \
			"Development;IDE;Qt;" \
			true

OPTIONS_DEFINE=	TOOLS DOCS NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguist_build
TOOLS_DESC=	Install Qt 4 development tools (qmake, moc, etc.)
TOOLS_USE=	${_TOOLS:C|.*|QT4=&_run|}
_TOOLS=		assistant linguist moc qmake rcc uic

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|\"qmake\"|\"qmake-qt4\"|g" \
		-e "s|\"linguist\"|\"linguist-qt4\"|g" \
		-e "s|\"lupdate\"|\"lupdate-qt4\"|g" \
		-e "s|\"lrelease\"|\"lrelease-qt4\"|g" \
		-e "s|\"designer\"|\"designer-qt4\"|g" \
		-e "s|\"assistant\"|\"assistant-qt4\"|g" \
		-e "s|\"/usr/bin/make\"|\"${LOCALBASE}/bin/gmake\"|g" \
		-e "s|\"/usr/bin/ctags\"|\"${LOCALBASE}/bin/exctags\"|g" \
		${WRKSRC}/src/toolscontrolimpl.cpp
	${REINPLACE_CMD} -e "/target.path/s|/usr/bin/|${PREFIX}/bin|g" \
		${WRKSRC}/QDevelop.pro
	${REINPLACE_CMD} -e "s,lib/qdevelop/translations,${DATADIR_REL}/translations,g" \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/plugins/tools-regexp-planner/replugin.cpp \
		${WRKSRC}/plugins/formatting-astyle/astyleplugin.cpp

post-configure:
.if ${PORT_OPTIONS:MNLS}
	${LRELEASE} ${WRKSRC}/QDevelop.pro
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
	${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/qdevelop.png
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/resources/translations/*.qm ${STAGEDIR}${DATADIR}/translations
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
