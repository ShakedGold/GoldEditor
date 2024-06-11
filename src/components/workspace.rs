use super::{item, Component};
use eframe::egui;

pub struct Workspace;

impl Workspace {
    pub fn new() -> Self {
        Self
    }
}

impl Component for Workspace {
    fn render(&self, _ctx: &egui::Context, ui: &mut egui::Ui) -> bool {
        ui.add(egui::Label::new("Workspace"));
        false
    }
}
