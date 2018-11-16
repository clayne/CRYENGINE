// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

class CSelectProjectDialog;
class CTemplatesModel;
class CTemplatesSortProxyModel;
class QAdvancedTreeView;
class QButtonGroup;
class QLineEdit;
class QPushButton;
class QThumbnailsView;
class QVBoxLayout;

class CCreateProjectPanel : public QWidget
{
public:
	CCreateProjectPanel(CSelectProjectDialog* pParent, bool runOnSandboxInit);

private:
	void CreateSearchPanel();
	void CreateViews();
	void CreateListViewButton(QButtonGroup* pGroup);
	void CreateThumbnailButton(QButtonGroup* pGroup);
	void CreateOutputRootFolderEditBox();
	void CreateProjectNameEditBox();
	void CreateDialogButtons(bool runOnSandboxInit);

	void SetViewMode(bool thumbnailMode);
	void OnCreateProjectPressed();
	void OnItemDoubleClicked(const QModelIndex& index);
	void OnSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
	void OnChangeOutputRootFolder();
	void OnNewProjectNameChanged(const QString& newProjectName);
	void UpdateCreateProjectBtn();

	CSelectProjectDialog*     m_pParent;

	CTemplatesModel*          m_pModel;
	CTemplatesSortProxyModel* m_pSortedModel;

	QVBoxLayout*              m_pMainLayout;
	QAdvancedTreeView*        m_pTreeView;
	QThumbnailsView*          m_pThumbnailView;
	QPushButton*              m_pCreateProjectBtn;
	QLineEdit*                m_pOutputRootEdit;
	QLineEdit*                m_pNewProjectNameEdit;
};